#include <iostream>
#include <vector>
using namespace std;

// Places the pivot in its correct position
int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Sorts the array using Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    // Base case
    if (low >= high) {
        return;
    }

    int pivotIndex = partitionArray(arr, low, high);

    // Recursively sort the two parts
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

// Displays the array
void display(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    display(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    display(arr);

    return 0;
}