# Unit 04 – Dynamic Programming

## 1. Overview

This unit introduces the Dynamic Programming approach for solving optimization and computational problems. Dynamic Programming solves complex problems by breaking them into smaller overlapping subproblems and storing their results to avoid repeated calculations.

The unit focuses on Memoization, Optimal Substructure, and solving problems involving Fibonacci numbers, Knapsack, Shortest Paths, Multistage Graphs, and Travelling Salesperson Problem (TSP).

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. Memoized Fibonacci
2. 0/1 Knapsack
3. Multistage Graph
4. Floyd-Warshall Algorithm
5. Shortest Path using Dynamic Programming (Bellman-Ford)
6. Travelling Salesperson Problem (TSP)

## 3. Memoized Fibonacci

### Problem Statement

Given an integer n, calculate the nth Fibonacci number using Dynamic Programming with Memoization.

### Algorithm / Approach

Memoization is a top-down Dynamic Programming technique. It stores previously calculated Fibonacci values in an array to avoid repeated calculations.

1. Create a memoization array initialized with -1.
2. If n is 0 or 1, return n.
3. Check whether the result is already calculated.
4. If calculated, return the stored result.
5. Otherwise, recursively calculate the two previous Fibonacci numbers.
6. Store and return the result.

### Pseudocode

```text
FIBONACCI(n, dp)

    IF n <= 1
        RETURN n

    IF dp[n] != -1
        RETURN dp[n]

    dp[n] = FIBONACCI(n-1, dp)
            + FIBONACCI(n-2, dp)

    RETURN dp[n]
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(n) |
| Worst Case | O(n) |

**Space Complexity:** O(n) due to the memoization array and recursive call stack.

### Sample Input

```text
Enter n: 7
```

### Sample Output

```text
Fibonacci number: 13
```

## 4. 0/1 Knapsack

### Problem Statement

Given n items, each having a weight and value, and a knapsack with a fixed capacity W, find the maximum total value that can be obtained without exceeding the capacity.

Each item can either be selected completely or not selected at all.

### Algorithm / Approach

The 0/1 Knapsack problem uses Dynamic Programming to find the maximum possible value.

1. Create a DP table of size (n+1) × (W+1).
2. Initialize the first row and column with zero.
3. Consider each item one by one.
4. If the item's weight exceeds the current capacity, exclude it.
5. Otherwise, choose the maximum value between including and excluding the item.
6. The final answer is stored in dp[n][W].

### Pseudocode

```text
KNAPSACK(weight, value, n, W)

    CREATE dp[n+1][W+1]

    FOR i = 0 to n
        FOR w = 0 to W

            IF i == 0 OR w == 0
                dp[i][w] = 0

            ELSE IF weight[i-1] <= w

                dp[i][w] = MAX(
                    value[i-1] + dp[i-1][w-weight[i-1]],
                    dp[i-1][w]
                )

            ELSE
                dp[i][w] = dp[i-1][w]

    RETURN dp[n][W]
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(nW) |
| Average Case | O(nW) |
| Worst Case | O(nW) |

**Space Complexity:** O(nW) for the DP table.

### Sample Input

```text
Number of items: 3
Knapsack Capacity: 50

Weight  Value
10       60
20       100
30       120
```

### Sample Output

```text
Maximum Value: 220
```

## 5. Multistage Graph

### Problem Statement

Given a weighted directed multistage graph, find the shortest path from the source vertex to the destination vertex.

### Algorithm / Approach

A Multistage Graph is a directed graph in which vertices are divided into different stages. Edges connect vertices from an earlier stage to a later stage.

Dynamic Programming is used to calculate the minimum cost from each vertex to the destination.

1. Start from the destination vertex.
2. Assign its cost as zero.
3. Process vertices in reverse stage order.
4. For each vertex, calculate the minimum cost of reaching the destination through its adjacent vertices.
5. Store the minimum cost and the next vertex in the path.
6. Follow the stored path from source to destination.

### Pseudocode

```text
MULTISTAGE_GRAPH(graph, V)

    cost[destination] = 0

    FOR each vertex u in reverse order

        cost[u] = INFINITY

        FOR each adjacent vertex v

            IF graph[u][v] exists

                IF graph[u][v] + cost[v] < cost[u]

                    cost[u] = graph[u][v] + cost[v]
                    next[u] = v

    PRINT shortest path
    RETURN cost[source]
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(V + E) |
| Average Case | O(V + E) |
| Worst Case | O(V + E) |

**Space Complexity:** O(V) auxiliary space for storing minimum costs and next vertices, excluding graph storage.

### Sample Input

```text
Number of vertices: 8

Adjacency Matrix:

0 2 1 0 0 0 0 0
0 0 0 2 3 0 0 0
0 0 0 6 7 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 0 0 4 0
0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0
```

### Sample Output

```text
Shortest Path: 1 -> 2 -> 4 -> 6 -> 8

Minimum Cost: 7
```

## 6. Floyd-Warshall Algorithm

### Problem Statement

Given a weighted graph represented by an adjacency matrix, find the shortest distances between all pairs of vertices.

### Algorithm / Approach

Floyd-Warshall is a Dynamic Programming algorithm used to find all-pairs shortest paths in a weighted graph.

1. Initialize the distance matrix using the adjacency matrix.
2. Set the distance from each vertex to itself as zero.
3. Consider each vertex as an intermediate vertex.
4. Update the distance between every pair of vertices if a shorter path is found through the intermediate vertex.
5. Repeat for all vertices.
6. The final matrix contains the shortest distances between all pairs.

### Pseudocode

```text
FLOYD_WARSHALL(dist, V)

    FOR k = 0 to V-1

        FOR i = 0 to V-1

            FOR j = 0 to V-1

                IF dist[i][k] != INFINITY
                   AND dist[k][j] != INFINITY

                    dist[i][j] = MIN(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    )

    PRINT dist
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(V³) |
| Average Case | O(V³) |
| Worst Case | O(V³) |

**Space Complexity:** O(V²) for storing the distance matrix.

### Sample Input

```text
Number of vertices: 4

Adjacency Matrix:

0   5   INF 10
INF 0   3   INF
INF INF 0   1
INF INF INF 0
```

### Sample Output

```text
Shortest Distance Matrix:

0   5   8   9
INF 0   3   4
INF INF 0   1
INF INF INF 0
```

## 7. Shortest Path (Bellman-Ford Algorithm)

### Problem Statement

Given a weighted directed graph and a source vertex, find the shortest distance from the source vertex to all other vertices. The graph may contain negative edge weights.

### Algorithm / Approach

Bellman-Ford is a Dynamic Programming-based algorithm that calculates shortest paths by repeatedly relaxing all edges.

1. Initialize the distance of the source vertex as zero.
2. Initialize all other vertex distances as infinity.
3. Relax every edge V-1 times.
4. Update the distance of a destination vertex if a shorter path is found through an edge.
5. Perform one additional iteration to check for negative-weight cycles.
6. Display the shortest distances.

### Pseudocode

```text
BELLMAN_FORD(edges, V, E, source)

    FOR i = 0 to V-1
        dist[i] = INFINITY

    dist[source] = 0

    FOR i = 1 to V-1

        FOR each edge (u, v, weight)

            IF dist[u] != INFINITY
               AND dist[u] + weight < dist[v]

                dist[v] = dist[u] + weight

    FOR each edge (u, v, weight)

        IF dist[u] != INFINITY
           AND dist[u] + weight < dist[v]

            PRINT "Negative cycle detected"
            RETURN

    PRINT dist
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(VE) |
| Average Case | O(VE) |
| Worst Case | O(VE) |

**Space Complexity:** O(V) auxiliary space, excluding graph storage.

### Sample Input

```text
Number of vertices: 5
Number of edges: 8
Source vertex: 0

Source Destination Weight

0      1           -1
0      2            4
1      2            3
1      3            2
1      4            2
3      2            5
3      1            1
4      3           -3
```

### Sample Output

```text
Vertex    Distance from Source

0         0
1        -1
2         2
3        -2
4         1
```

## 8. Travelling Salesperson Problem (TSP)

### Problem Statement

Given a set of cities and the distances between every pair of cities, find the minimum-cost tour that visits every city exactly once and returns to the starting city.

### Algorithm / Approach

The Travelling Salesperson Problem can be solved using Dynamic Programming with Bitmasking.

1. Select a starting city.
2. Represent the visited cities using a bitmask.
3. Create a DP table to store the minimum cost of reaching a city with a particular set of visited cities.
4. Consider every unvisited city as the next destination.
5. Update the minimum travelling cost.
6. After visiting all cities, return to the starting city.
7. Calculate the minimum tour cost.

### Pseudocode

```text
TSP(dist, n)

    CREATE dp[2^n][n]
    INITIALIZE all values with INFINITY

    dp[1][0] = 0

    FOR mask = 1 to (2^n)-1

        FOR u = 0 to n-1

            IF u is visited in mask

                FOR v = 0 to n-1

                    IF v is not visited in mask

                        newMask = mask | (1 << v)

                        dp[newMask][v] = MIN(
                            dp[newMask][v],
                            dp[mask][u] + dist[u][v]
                        )

    answer = INFINITY

    FOR u = 1 to n-1

        answer = MIN(
            answer,
            dp[(2^n)-1][u] + dist[u][0]
        )

    RETURN answer
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n² × 2ⁿ) |
| Average Case | O(n² × 2ⁿ) |
| Worst Case | O(n² × 2ⁿ) |

**Space Complexity:** O(n × 2ⁿ) for the DP table.

### Sample Input

```text
Number of cities: 4

Distance Matrix:

0  10  15  20
10  0  35  25
15 35   0  30
20 25  30   0
```

### Sample Output

```text
Minimum Tour Cost: 80
```

## 9. Comparison of Algorithms

| Algorithm | Time Complexity |
|---|---|
| Memoized Fibonacci | O(n) |
| 0/1 Knapsack | O(nW) |
| Multistage Graph | O(V + E) |
| Floyd-Warshall | O(V³) |
| Bellman-Ford | O(VE) |
| TSP (Bitmask DP) | O(n² × 2ⁿ) |

## 10. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding the Dynamic Programming approach.
2. Understanding Memoization and overlapping subproblems.
3. Implementing Fibonacci using Memoization.
4. Solving the 0/1 Knapsack problem.
5. Finding shortest paths in Multistage Graphs.
6. Finding all-pairs shortest paths using Floyd-Warshall.
7. Finding shortest paths using Bellman-Ford.
8. Solving the Travelling Salesperson Problem using Bitmasking.
9. Understanding optimal substructure.
10. Comparing time and space complexities of Dynamic Programming algorithms.

## 11. Files in This Unit

```text
Unit-4-dynamic-programming/
│
├── memoizedFibonacci.cpp
├── zeroOneKnapsack.cpp
├── multistageGraph.cpp
├── floydWarshall.cpp
├── shortestPath.cpp
├── tsp.cpp
└── README.md
```

## 12. Conclusion

This unit introduces Dynamic Programming as an efficient approach for solving complex optimization problems. The implementations demonstrate how storing previously calculated results avoids repeated computations and improves efficiency.

Memoized Fibonacci, 0/1 Knapsack, Multistage Graph, Floyd-Warshall, Bellman-Ford, and Travelling Salesperson Problem provide practical examples of Dynamic Programming applications in C++.