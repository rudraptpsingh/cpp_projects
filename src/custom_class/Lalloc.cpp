/*
Given an array of memory buffers (100), each of size 4096 bytes, implement:
Handle Lalloc(uint size).  size <= 512 bytes
Lfree(Handle)
*/
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

class MemoryManager {
public:
    MemoryManager() {
        freeblocks.resize(bins.size());
        freeblocks[bins.size()-1].push_back({new char[blockSize], blockSize});
    }

    void* Lalloc(int size) {
        int binIndex = getBinIndex(size);
        if (binIndex == -1) {
            throw std::invalid_argument("Memory not present\n");
        }

        for (size_t i = binIndex; i < bins.size(); i++) {
            if (freeblocks[i].empty()) {
                continue;
            }

            auto it = freeblocks[i].begin();
            int currBlockSize = it->second;
            if (it->second >= size) {
                std::cout << "allocating from bin: " << i << endl; 
                char* allocatedBlock = it->first;
                char* remainingBlock = allocatedBlock + size;
                int remainingSize = currBlockSize - size;
                if (remainingSize > 0) {
                    int newIndex = getBinIndex(remainingSize);
                    if (binIndex == -1) {
                        throw std::invalid_argument("Invalid bin index\n");
                    }
                    freeblocks[newIndex].push_back({remainingBlock, remainingSize});
                }
                
                freeblocks[i].erase(it);
                allocations[allocatedBlock] = size;
                return allocatedBlock;
            }
        }

        throw std::runtime_error("No available block to allocate\n");
    }

    void Lfree(void *ptr) {
        char *handle = static_cast<char *>(ptr);
        if (allocations.find(handle) == allocations.end()) {
            throw std::runtime_error("Invalid handle or block being freed.\n");
        }

        int size = allocations[handle];
        int binIndex = getBinIndex(size);
        allocations.erase(handle);
        freeblocks[binIndex].push_back({handle, size});
        cout << "freed block moved to bin: " << binIndex << " with block size : " << size << endl;
    }

    int getBinIndex(int size) {

        if (size >= bins.back()) {
            return bins.size()-1;
        }

        for (int i = 0; i < bins.size(); i++) {
            if (bins[i] >= size) {
                return i;
            }
        }

        return -1;
    }


private:
    vector<list<pair<char *, int>>> freeblocks;
    unordered_map<char *, int> allocations;
    const int blockSize = 4096;
    const int totalBlocks = 100;
    const vector<int> bins = {2, 4, 8, 16, 32, 64, 128, 256, 512};
};

int main() {
    MemoryManager mm;
    vector<void*> buffers;
    char *buff = static_cast<char *>(mm.Lalloc(100));
    mm.Lfree(buff);
}