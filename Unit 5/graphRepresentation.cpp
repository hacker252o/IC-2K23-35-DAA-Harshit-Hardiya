#include <iostream>
#include <vector>
using namespace std;

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Adjacency Matrix
    vector<vector<int>> matrix(V, vector<int>(V, 0));

    // Adjacency List
    vector<vector<int>> adjList(V);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        // Update adjacency matrix
        matrix[u][v] = 1;
        matrix[v][u] = 1;

        // Update adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display Adjacency Matrix
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display Adjacency List
    cout << "\nAdjacency List:\n";

    for (int i = 0; i < V; i++) {

        cout << i << " -> ";

        for (int j : adjList[i]) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}