#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Sort jobs according to profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "Enter job ID, deadline and profit:\n";

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }

    // Sort jobs by profit
    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Initialize time slots
    char slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++) {
        slot[i] = '-';
    }

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {

        for (int j = jobs[i].deadline; j >= 1; j--) {

            if (slot[j] == '-') {

                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    cout << "\nSelected Jobs: ";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-') {
            cout << slot[i] << " ";
        }
    }

    cout << "\nMaximum Profit: " << totalProfit;

    return 0;
}