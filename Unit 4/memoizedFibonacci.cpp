#include <iostream>
#include <vector>
using namespace std;

// Function to calculate Fibonacci using Memoization
int fibonacci(int n, vector<int>& dp) {

    // Base case
    if (n <= 1)
        return n;

    // Return stored result if already calculated
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store result
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);

    return dp[n];
}

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    int result = fibonacci(n, dp);

    cout << "Fibonacci number: " << result;

    return 0;
}