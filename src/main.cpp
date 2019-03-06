#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {2,3,4,5};
    for (int i : a) {
        std::cout << i << std::endl;
    }
}