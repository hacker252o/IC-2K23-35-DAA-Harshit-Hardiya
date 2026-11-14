#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack
int knapsack(int weight[], int value[], int n, int W) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= W; w++) {

            if (weight[i - 1] <= w) {

                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int result = knapsack(weight, value, n, W);

    cout << "Maximum Value: " << result;

    return 0;
}