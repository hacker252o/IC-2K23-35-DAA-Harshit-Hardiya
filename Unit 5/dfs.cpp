#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {

    // Mark current vertex as visited
    visited[node] = true;

    cout << node << " ";

    // Visit all unvisited neighbours
    for (int neighbour : adj[node]) {

        if (!visited[neighbour]) {
            DFS(neighbour, adj, visited);
        }
    }
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";

    DFS(start, adj, visited);

    cout << endl;

    return 0;
}