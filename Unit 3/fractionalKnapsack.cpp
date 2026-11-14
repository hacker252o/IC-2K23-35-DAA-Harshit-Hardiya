#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
    double ratio;
};

// Compare items according to value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by value/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}