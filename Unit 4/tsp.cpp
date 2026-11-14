#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define INF INT_MAX

int n;
int dp[16][1 << 16];
int dist[16][16];

// TSP using Dynamic Programming and Bitmasking
int tsp(int mask, int pos) {

    // If all cities are visited, return to starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // Return stored result
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INF;

    // Visit unvisited cities
    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0 &&
            dist[pos][city] != INF) {

            int newCost = tsp(mask | (1 << city), city);

            if (newCost != INF) {
                ans = min(ans, dist[pos][city] + newCost);
            }
        }
    }

    return dp[pos][mask] = ans;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 1 || n > 16) {
        cout << "Number of cities must be between 1 and 16.";
        return 0;
    }

    cout << "Enter distance matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];

            if (i != j && dist[i][j] == -1) {
                dist[i][j] = INF;
            }
        }
    }

    // Initialize DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);

    if (result == INF) {
        cout << "No complete tour exists.";
    }
    else {
        cout << "Minimum Tour Cost: " << result;
    }

    return 0;
}