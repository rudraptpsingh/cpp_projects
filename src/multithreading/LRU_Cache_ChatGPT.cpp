#include <iostream>
#include <unordered_map>
#include <list>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

std::mutex consoleMutex;

template <typename Key, typename Value>
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity_(capacity) {}

    Value get(const Key& key) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return allowOperation_; });  // Wait until allowed to proceed

        std::shared_lock<std::shared_mutex> cacheLock(cacheMutex_);

        auto it = cache_.find(key);
        if (it != cache_.end()) {
            {
                std::unique_lock<std::shared_mutex> orderLock(orderMutex_);
                order_.splice(order_.begin(), order_, it->second);
            }
            return it->second->second;
        }

        return Value();
    }

    void put(const Key& key, const Value& value) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this] { return allowOperation_; });  // Wait until allowed to proceed

        {
            std::unique_lock<std::shared_mutex> cacheLock(cacheMutex_);

            auto it = cache_.find(key);
            if (it != cache_.end()) {
                it->second->second = value;
            } else {
                if (cache_.size() >= capacity_) {
                    const Key& evictedKey = order_.back().first;
                    cache_.erase(evictedKey);
                    order_.pop_back();
                }

                order_.emplace_front(key, value);
                cache_[key] = order_.begin();
            }
        }

        {
            std::unique_lock<std::shared_mutex> orderLock(orderMutex_);
            // Additional operations on 'order_' if needed
        }
    }

    // Function to signal that the operation can proceed
    void allowOperation() {
        std::unique_lock<std::mutex> lock(mutex_);
        allowOperation_ = true;
        cv_.notify_all();
    }

private:
    size_t capacity_;
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cache_;
    std::list<std::pair<Key, Value>> order_;
    mutable std::shared_mutex cacheMutex_;
    mutable std::shared_mutex orderMutex_;
    std::mutex mutex_;  // Mutex for condition variable and synchronization
    std::condition_variable cv_;
    bool allowOperation_ = false;  // Flag to control when threads can proceed
};

int main() {
    // Example usage of LRUCache with synchronized put and get calls using threads

    LRUCache<int, std::string> cache(2);

    // Function to perform put operations
    auto putFunction = [&cache](int key, std::string value) {
        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            std::cout << "Thread " << std::this_thread::get_id() << ": Put: Key " << key << ", Value " << value << std::endl;
        }
        cache.put(key, value);
        cache.allowOperation();  // Signal that the operation is completed
    };

    // Function to perform get operations
    auto getFunction = [&cache](int key) {
        {
            std::lock_guard<std::mutex> consoleLock(consoleMutex);
            std::cout << "Thread " << std::this_thread::get_id() << ": Get: Key " << key << std::endl;
        }
        cache.get(key);
        cache.allowOperation();  // Signal that the operation is completed
    };

    // Create multiple threads for put and get operations
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(putFunction, i, "Value" + std::to_string(i));
        threads.emplace_back(getFunction, i);
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
