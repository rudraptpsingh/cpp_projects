#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<int>& arr) {
    bool swapped;
    auto arrsize = arr.size();
    for (int i = 0; i < arrsize - 1 && i >= 0 ; ++i) {
        swapped = false;
        for (int j = 0; j < arrsize - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) { // Optimize by returning if no elements were swapped(array already sorted)
            return;
        }
    }
}

void bubblesort_recursive(vector<int>& arr, int arrsize) {
    if (arrsize == 0 || arrsize == 1) {
        return;
    }

    for (int i = 0; i < arrsize - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubblesort_recursive(arr, arrsize - 1);
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

    bubblesort(arr);
    cout << "Bubble sorted array is: " << endl;
    for (auto i : arr) {
        cout << i << endl;
    }

    // bubblesort_recursive(arr, arrsize);
    // cout << "Bubble sorted array is(recursive): " << endl;
    // for (auto i : arr) {
    //     cout << i << endl;
    // }

    return 0;
}