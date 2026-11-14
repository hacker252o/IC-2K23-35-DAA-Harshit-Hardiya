#include <iostream>
#include <vector>
using namespace std;

// Performs Binary Search recursively.
// The array must be sorted.
int recursiveBinarySearch(
    const vector<int>& arr,
    int left,
    int right,
    int target
) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }

    return recursiveBinarySearch(arr, left, mid - 1, target);
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};

    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = recursiveBinarySearch(
        arr,
        0,
        arr.size() - 1,
        target
    );

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}