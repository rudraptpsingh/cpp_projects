/*
This file implements the LRU cache, with thread-safe operation.
*/

#include <iostream>
#include <list>
#include <shared_mutex>
#include <map>
#include <thread>

using namespace std;

class LRUCache {
public:
    LRUCache(int _capacity) : capacity(_capacity) {}

    void get(int key) {
        unique_lock lock(mt);
        if (m.find(key) == m.end()) {
            cout << "Key " << key << " not found\n";
            return;
        }

        ls.splice(ls.begin(), ls, m[key].second);
        cout << "Value for " << key << " is: " << m[key].first << endl;
        cout << "Get: New list is: "; 
        printlist();
        cout << endl;
    }

    void put(int key, int value) {
        unique_lock lock(mt);
        if (ls.size() >= capacity) {
            m.erase(ls.back());
            ls.pop_back();
        }

        ls.push_front(key);
        m[key] = make_pair(value, ls.begin());
        cout << "Put: New list is: "; 
        printlist();
        cout << endl;
    }

    void printlist() {
        for (auto it = ls.begin(); it != ls.end(); it++) {
            cout << *it << " ";
        }
        this_thread::sleep_for(chrono::seconds(2));
    }


private:
    int capacity;
    list<int> ls;
    map<int, pair<int, list<int>::iterator>> m;
    mutable shared_mutex mt;
};

int main() {
    LRUCache cache(5);
    vector<thread> threads;

    threads.push_back(thread(&LRUCache::get, &cache, 2));
    threads.push_back(thread(&LRUCache::put, &cache, 1, 1));
    threads.push_back(thread(&LRUCache::get, &cache, 1));
    threads.push_back(thread(&LRUCache::put, &cache, 1, 10));
    threads.push_back(thread(&LRUCache::get, &cache, 1));   
    threads.push_back(thread(&LRUCache::put, &cache, 2, 20));
    threads.push_back(thread(&LRUCache::put, &cache, 3, 30));
    threads.push_back(thread(&LRUCache::put, &cache, 4, 40));
    //threads.push_back(thread(&LRUCache::printlist, &cache));
    threads.push_back(thread(&LRUCache::put, &cache, 5, 50));
    threads.push_back(thread(&LRUCache::get, &cache, 4));
    threads.push_back(thread(&LRUCache::get, &cache, 5));
    //threads.push_back(thread(&LRUCache::printlist, &cache));
    threads.push_back(thread(&LRUCache::put, &cache, 6, 60));
    //threads.push_back(thread(&LRUCache::printlist, &cache));
    threads.push_back(thread(&LRUCache::get, &cache, 3));
    //threads.push_back(thread(&LRUCache::printlist, &cache));

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    return 0;
}

