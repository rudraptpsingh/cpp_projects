#include <iostream>

template <typename T>
using custom_vector = std::vector<T>;

using ptr = int*;

int main() {
    custom_vector<int> v = {1, 2, 3};
    std::cout << v[0] << std::endl;   

    ptr p = new int[1];
    *p = 11;
    std::cout << *p << std::endl;
}