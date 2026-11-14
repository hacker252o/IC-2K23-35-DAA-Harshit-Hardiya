#include <iostream>
#include <vector>
using namespace std;

// Merges two sorted parts of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Add remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Add remaining elements from the right half
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back into the original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Sorts the array using Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    // Base case
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Divide the array
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combine the sorted halves
    merge(arr, left, mid, right);
}

// Displays the array
void display(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    display(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    display(arr);

    return 0;
}