#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(right + left) / 2];
    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }

        while (arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    
    return left;
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        if (left < index - 1) {
            quicksort(arr, left, index - 1);
        }

        if (right > index) {
            quicksort(arr, index, right);
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

    quicksort(arr, 0, arrsize - 1);
    cout << "Quick sorted array is: " << endl;
    for (auto i : arr) {
        cout << i << endl;
    }

    return 0;
}