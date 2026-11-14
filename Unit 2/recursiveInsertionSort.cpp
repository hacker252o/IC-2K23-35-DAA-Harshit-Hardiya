#include <iostream>
#include <vector>
using namespace std;

// Sorts the array using Recursive Insertion Sort
void recursiveInsertionSort(vector<int>& arr, int n) {
    // Base case
    if (n <= 1) {
        return;
    }

    // Sort the first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element into its correct position
    int key = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

// Displays the array
void display(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    display(arr);

    recursiveInsertionSort(arr, arr.size());

    cout << "Sorted array: ";
    display(arr);

    return 0;
}