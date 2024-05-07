#include <iostream>

using namespace std;

class Integer {
public:

    Integer(int size) : size(size), m_data(new int[size]) {}

    int& operator*() {
        return *m_data;
    }

    int* operator->() {
        return m_data;
    }

    int* operator++() {
        ++m_data;
        return m_data;
    }

    int* operator++(int) {
        Integer tmp = *this;
        ++tmp.m_data;
        return tmp.m_data;
    }

    int& operator[](int n) const {
        return *(m_data + n);
    }

    friend bool operator==(const Integer& a, const Integer& b) {
            return a.m_data == b.m_data;
        }

    friend bool operator!=(const Integer& a, const Integer& b) {
        return a.m_data != b.m_data;
    }

    int* begin() {
        return &m_data[0];
    }

    int* end() {
        return &m_data[size];
    }

private:
    int size;
    int *m_data;
};

int main() {
    Integer integer(5);
    fill(integer.begin(), integer.begin() + 1, 1);
    fill(integer.begin()+1, integer.begin() + 2, 2);
    fill(integer.begin()+2, integer.begin() + 3, 3);
    fill(integer.begin()+3, integer.begin() + 4, 4);
    fill(integer.begin()+4, integer.begin() + 5, 5);
    for (auto it = integer.begin(); it != integer.end(); ++it) {
        cout << *it << endl;
    }

    cout << integer[2] << endl;
}
