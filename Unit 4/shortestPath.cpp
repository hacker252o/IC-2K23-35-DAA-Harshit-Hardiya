#include <iostream>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Bellman-Ford Algorithm
void bellmanFord(Edge edges[], int V, int E, int source) {

    int dist[V];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int i = 0; i < E; i++) {

        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {

            cout << "Negative weight cycle detected!";
            return;
        }
    }

    // Print shortest distances
    cout << "\nVertex\tDistance from Source\n";

    for (int i = 0; i < V; i++) {

        cout << i << "\t";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {

    int V = 5;
    int E = 8;

    Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;

    bellmanFord(edges, V, E, source);

    return 0;
}