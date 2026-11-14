#include <iostream>
#include <climits>
using namespace std;

#define V 8

// Function to find shortest path in Multistage Graph
void multistageGraph(int graph[V][V]) {

    int cost[V];
    int path[V];

    // Initialize costs
    cost[V - 1] = 0;

    // Calculate minimum cost from destination
    for (int i = V - 2; i >= 0; i--) {

        cost[i] = INT_MAX;

        for (int j = i + 1; j < V; j++) {

            if (graph[i][j] != 0 &&
                cost[j] != INT_MAX) {

                int newCost = graph[i][j] + cost[j];

                if (newCost < cost[i]) {
                    cost[i] = newCost;
                    path[i] = j;
                }
            }
        }
    }

    // Print shortest path
    cout << "Shortest Path: ";

    int current = 0;

    while (current != V - 1) {
        cout << current + 1 << " -> ";
        current = path[current];
    }

    cout << V << endl;

    cout << "Minimum Cost: " << cost[0];
}

int main() {

    int graph[V][V] = {
        {0, 2, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 3, 0, 0, 0},
        {0, 0, 0, 6, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    multistageGraph(graph);

    return 0;
}
