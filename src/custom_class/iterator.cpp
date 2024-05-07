#include <iostream>

using namespace std;

/*The first step is to choose the type of iterator we want to implement. Modern C++ defines six types:

#	Name	Description
1	Input Iterator	Can scan the container forward only once, can't change the value it points to (read-only);
2	Output Iterator	Can scan the container forward only once, can't read the value it points to (write-only);
3	Forward Iterator	Can scan the container forward multiple times, can read and write the value it points to;
4	Bidirectional Iterator	Same as previous one but can scan the container back and forth;
5	Random Access Iterator	Same as previous one but can access the container also non-sequentially (i.e. by jumping around);
6	Contiguous Iterator	Same as previous one, with the addition that logically adjacent elements are also physically adjacent in memory.
The six categories are hierarchical: a Bidirectional Iterator is also a Forward Iterator and a Random Access Iterator is both a Bidirectional and a Forward Iterator and so on.
Normally, all iterators are Input Iterators (1) which makes them read-only, also known as constant iterators. Iterators that both support read and write operations are also Output Iterators (2) and are called mutable iterators.

Input and Output iterators are often used for low-level components such as input and output streams (the so-called single-pass algorithms) and thus have limitations.
We want to do more with our custom container, so we will skip those two and jump straight to the mutable Forward Iterator.
*/
class Integer {
public:

    Integer(int len) : size(len), m_data(new int[size]) {}

    /*
    C++ expects some properties from an iterator:

    iterator_category — one of the six iterator categories we have seen above. The full list is available here. The std::forward_iterator_tag tag is what we need;
    difference_type — a signed integer type that can be used to identify distance between iterator steps. Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic, so the default std::ptrdiff_t is a good choice;
    value_type — the type the iterator iterates over. int in our case;
    pointer — defines a pointer to the type iterated over. int* in our case;
    reference — defines a reference to the type iterated over. int& in our case;
    */
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = value_type*;
        using reference = value_type&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const {
            return *m_ptr;
        }

        pointer operator->() {
            return m_ptr;
        }

        reference operator[](difference_type n) const { return *(m_ptr + n); }

        Iterator& operator++() {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        }

        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.m_ptr != b.m_ptr;
        }

    private:
        pointer m_ptr;
    };

    Iterator begin() {
        return Iterator(&m_data[0]);
    }

    Iterator end() {
        return Iterator(&m_data[size]); // a placeholder to check if boundary has been reached. Should not be used directly.
    }
    

private:
    int size;
    int *m_data;
};

int main() {
    Integer integer(5);
    std::fill(integer.begin(), integer.end(), 3);
    // std::reverse wouldn't work as it requires a bidirectional iterator which isn't implemented
    for (auto i : integer) {
        cout << i << endl;
    }

    //above code is compiled to the following
    for (auto it = integer.begin(); it != integer.end(); ++it) {
        cout << *it <<endl;
    }
}