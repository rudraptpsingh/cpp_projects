#include <iostream>
#include <vector>

using namespace std;

void selectionsort(vector<int>& arr) {
    auto arrsize = arr.size();
    int min_index;
    for (int i = 0; i < arrsize - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < arrsize; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    int arrsize = 0;
    int arrnum;
    cout << "Enter the size of the array: " << endl;
    cin >> arrsize;
    cout << "Enter the elements of the array: " << endl;
    vector<int> arr;
    for (int i = 0; i < arrsize; ++i) {
        cin >> arrnum;
        arr.push_back(arrnum);
    }

    selectionsort(arr);
    cout << "Selection sorted array is: " << endl;
    for (auto i : arr) {
        cout << i << endl;
    }

    return 0;
}