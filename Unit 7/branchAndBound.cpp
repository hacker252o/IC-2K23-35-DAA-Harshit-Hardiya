#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int minCost = INT_MAX;
vector<int> bestPath;

void tsp(vector<vector<int>>& cost, vector<bool>& visited,
         vector<int>& path, int currentCity, int count, int currentCost) {

    // All cities visited
    if (count == n) {
        int totalCost = currentCost + cost[currentCity][0];

        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = path;
            bestPath.push_back(0);
        }
        return;
    }

    // Branch and Bound: prune costly paths
    if (currentCost >= minCost)
        return;

    for (int city = 0; city < n; city++) {
        if (!visited[city] && cost[currentCity][city] > 0) {

            visited[city] = true;
            path.push_back(city);

            tsp(cost, visited, path, city,
                count + 1, currentCost + cost[currentCity][city]);

            // Backtracking
            visited[city] = false;
            path.pop_back();
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<bool> visited(n, false);
    vector<int> path;

    visited[0] = true;
    path.push_back(0);

    tsp(cost, visited, path, 0, 1, 0);

    if (minCost == INT_MAX) {
        cout << "No valid tour exists.\n";
    } else {
        cout << "\nMinimum Cost: " << minCost;
        cout << "\nOptimal Path: ";

        for (int city : bestPath) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}