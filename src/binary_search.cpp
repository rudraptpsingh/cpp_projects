#include <iostream>
#include <vector>

using namespace std;

void binary_search(vector<int>& arr, int findnum) {
    int start = 0;
    int end = arr.size() - 1;
    auto mid = 0;
    while (start <= end) {
        mid = start + (end - start) / 2; // Handling out of bounds index exception
        if (arr[mid] == findnum) {
            break;
        } else if (arr[mid] > findnum) {
            end = mid - 1;
        } else if (arr[mid] < findnum) {
            start = mid + 1;
        }
    }

    if (start <= end) {
        cout << "The number was found at postion: " << mid + 1 << endl; 
    } else {
        cout << "Element not found" << endl;
    }

}

int binary_search_recursive(vector<int>& arr, int start, int end, int findnum) {
    if (start <= end) {
        auto mid = start + (end - start) / 2; // Handling out of bounds index exception
        if (arr[mid] == findnum) {
            return mid; 
        } else if (arr[mid] > findnum) {
            end = mid - 1;
        } else if (arr[mid] < findnum) {
            start = mid + 1;
        }

        return binary_search_recursive(arr, start, end, findnum);
    }

     return -1;   
}

int main() {
    int arrsize = 0;
    int arrnum;
    int findnum;
    int result;
    cout << "Enter the size of the array: " << endl;
    cin >> arrsize;
    cout << "Enter the elements of the array(in sorted order): " << endl;
    vector<int> arr;
    for (int i = 0; i < arrsize; ++i) {
        cin >> arrnum;
        arr.push_back(arrnum);
    }

    cout << "Enter the element to search: " << endl;
    cin >> findnum;
    cout << "Result using iterative search: " << endl;
    binary_search(arr, findnum);
    cout << "Result using recursive search: " <<endl;
    result = binary_search_recursive(arr, 0, arrsize - 1, findnum);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "The number was found at postion: " << result + 1 << endl; 
    }
}