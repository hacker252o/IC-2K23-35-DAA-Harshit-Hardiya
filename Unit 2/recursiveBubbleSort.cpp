#include <iostream>
#include <vector>
using namespace std;

// Sorts the array using Recursive Bubble Sort
void recursiveBubbleSort(vector<int>& arr, int n) {
    // Base case
    if (n <= 1) {
        return;
    }

    bool swapped = false;

    // Perform one pass of Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    // If no swapping occurred, the array is sorted
    if (!swapped) {
        return;
    }

    // Recursively sort the remaining elements
    recursiveBubbleSort(arr, n - 1);
}

// Displays the array
void display(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    display(arr);

    recursiveBubbleSort(arr, arr.size());

    cout << "Sorted array: ";
    display(arr);

    return 0;
}