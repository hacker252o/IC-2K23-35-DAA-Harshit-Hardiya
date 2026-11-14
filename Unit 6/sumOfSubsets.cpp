#include <iostream>
#include <vector>
using namespace std;

void sumOfSubsets(vector<int>& arr, vector<int>& subset,
                  int index, int currentSum, int target) {

    if (currentSum == target) {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}" << endl;
        return;
    }

    if (index == arr.size() || currentSum > target)
        return;

    // Include the current element
    subset.push_back(arr[index]);

    sumOfSubsets(arr, subset, index + 1,
                 currentSum + arr[index], target);

    // Backtrack: exclude the current element
    subset.pop_back();

    sumOfSubsets(arr, subset, index + 1,
                 currentSum, target);
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> subset;

    cout << "\nSubsets with sum " << target << ":\n";

    sumOfSubsets(arr, subset, 0, 0, target);

    return 0;
}