#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Sort edges according to weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find parent of a vertex
int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] =
        findParent(parent, parent[vertex]);
}

// Union of two sets
void unionSet(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[u] > rank[v])
        parent[v] = u;

    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E) {

    sort(edges, edges + E, compare);

    int parent[V];
    int rank[V] = {0};

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < E && edgeCount < V - 1; i++) {

        int u = findParent(parent, edges[i].src);
        int v = findParent(parent, edges[i].dest);

        // Check whether edge forms a cycle
        if (u != v) {

            cout << edges[i].src << " - "
                 << edges[i].dest << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, rank, u, v);

            edgeCount++;
        }
    }

    if (edgeCount != V - 1) {
        cout << "Spanning tree does not exist.";
        return;
    }

    cout << "\nMinimum Cost: " << totalCost;
}

int main() {

    int V = 5;
    int E = 7;

    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskal(edges, V, E);

    return 0;
}