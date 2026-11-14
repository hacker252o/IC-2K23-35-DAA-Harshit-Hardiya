# Unit 03 – Greedy Method

## 1. Overview

This unit introduces the Greedy Method, an algorithmic approach used to solve optimization problems by making the locally optimal choice at each step.

The unit focuses on understanding and implementing Fractional Knapsack, Job Sequencing with Deadlines, Prim's Algorithm, and Kruskal's Algorithm.

These algorithms are widely used in resource allocation, scheduling, network design, and optimization problems.

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. Fractional Knapsack
2. Job Sequencing with Deadlines
3. Prim's Algorithm
4. Kruskal's Algorithm

## 3. Fractional Knapsack

### Problem Statement

Given a set of items, each having a value and weight, and a knapsack with a fixed capacity, find the maximum total value that can be obtained by selecting items or fractions of items.

### Algorithm / Approach

Fractional Knapsack follows the Greedy Method. It selects items according to their value-to-weight ratio in descending order.

1. Calculate the value-to-weight ratio of each item.
2. Sort all items in descending order of their ratios.
3. Select the item with the highest ratio.
4. If the complete item fits, add its value to the total.
5. Otherwise, take the fraction that fits into the remaining capacity.
6. Repeat until the knapsack becomes full or all items are considered.

### Pseudocode

```text
FRACTIONAL_KNAPSACK(items, n, capacity)

    FOR each item
        ratio = value / weight

    SORT items by ratio in descending order

    totalValue = 0

    FOR i = 0 to n-1

        IF capacity == 0
            BREAK

        IF items[i].weight <= capacity
            totalValue += items[i].value
            capacity -= items[i].weight

        ELSE
            totalValue += items[i].ratio * capacity
            capacity = 0

    RETURN totalValue
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |

**Space Complexity:** O(n) for storing the items.

### Sample Input

```text
Number of items: 3

Value  Weight
60     10
100    20
120    30

Knapsack Capacity: 50
```

### Sample Output

```text
Maximum value: 240
```

## 4. Job Sequencing with Deadlines

### Problem Statement

Given a set of jobs, each having a deadline and a profit, schedule the jobs to maximize the total profit. Each job takes one unit of time, and only one job can be performed at a time.

### Algorithm / Approach

Job Sequencing follows the Greedy Method. The objective is to select jobs in such a way that maximum profit is obtained while completing each job before its deadline.

1. Sort all jobs in descending order of profit.
2. Find the maximum deadline among all jobs.
3. Create an array of time slots initialized as empty.
4. Select jobs one by one in descending order of profit.
5. Place each job in the latest available slot before or on its deadline.
6. Calculate the total profit of the scheduled jobs.

### Pseudocode

```text
JOB_SEQUENCING(jobs, n)

    SORT jobs by profit in descending order

    maxDeadline = maximum deadline

    CREATE slots[maxDeadline]
    INITIALIZE all slots as empty

    totalProfit = 0

    FOR i = 0 to n-1

        FOR j = jobs[i].deadline DOWNTO 1

            IF slots[j] is empty

                slots[j] = jobs[i]
                totalProfit += jobs[i].profit

                BREAK

    RETURN totalProfit
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n + nD) |
| Average Case | O(n log n + nD) |
| Worst Case | O(n log n + nD) |

Here, D represents the maximum deadline.

**Space Complexity:** O(D) for storing the time slots.

### Sample Input

```text
Number of jobs: 5

Job   Deadline   Profit
J1       2         100
J2       1          19
J3       2          27
J4       1          25
J5       3          15
```

### Sample Output

```text
Selected Jobs: J3 J1 J5
Maximum Profit: 142
```

## 5. Prim's Algorithm

### Problem Statement

Given a connected, weighted, undirected graph, find its Minimum Spanning Tree (MST) using Prim's Algorithm.

### Algorithm / Approach

Prim's Algorithm is a Greedy algorithm used to find the Minimum Spanning Tree of a connected weighted graph.

1. Start from any vertex.
2. Mark the starting vertex as visited.
3. Find the minimum-weight edge connecting a visited vertex to an unvisited vertex.
4. Add that edge to the Minimum Spanning Tree.
5. Mark the newly selected vertex as visited.
6. Repeat until all vertices are included in the MST.

### Pseudocode

```text
PRIM(graph, V)

    visited[V] = false

    key[0] = 0
    key[all other vertices] = INFINITY

    parent[0] = -1

    FOR count = 0 to V-1

        u = vertex with minimum key
            among unvisited vertices

        visited[u] = true

        FOR each vertex v adjacent to u

            IF graph[u][v] != 0
               AND visited[v] == false
               AND graph[u][v] < key[v]

                parent[v] = u
                key[v] = graph[u][v]

    PRINT MST edges
    PRINT total MST weight
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(V²) |
| Average Case | O(V²) |
| Worst Case | O(V²) |

**Space Complexity:** O(V²) for the adjacency matrix implementation.

### Sample Input

```text
Number of vertices: 5

Adjacency Matrix:

0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
```

### Sample Output

```text
Minimum Spanning Tree:

0 - 1 : 2
1 - 2 : 3
1 - 4 : 5
0 - 3 : 6

Minimum Cost: 16
```

## 6. Kruskal's Algorithm

### Problem Statement

Given a connected, weighted, undirected graph, find its Minimum Spanning Tree using Kruskal's Algorithm.

### Algorithm / Approach

Kruskal's Algorithm is a Greedy algorithm that finds the Minimum Spanning Tree by selecting edges in increasing order of their weights.

1. Sort all edges in ascending order of weight.
2. Initialize each vertex as a separate set.
3. Select the edge with the minimum weight.
4. Check whether the selected edge forms a cycle.
5. If it does not form a cycle, include it in the MST.
6. If it forms a cycle, discard the edge.
7. Repeat until exactly V-1 edges are selected.

### Pseudocode

```text
KRUSKAL(graph, V, E)

    SORT all edges in ascending order of weight

    INITIALIZE Disjoint Set for all vertices

    totalCost = 0
    edgeCount = 0

    FOR each edge (u, v, weight)

        IF FIND(u) != FIND(v)

            UNION(u, v)

            ADD edge to MST

            totalCost += weight

            edgeCount++

        IF edgeCount == V-1
            BREAK

    PRINT MST edges
    PRINT totalCost
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(E log E) |
| Average Case | O(E log E) |
| Worst Case | O(E log E) |

**Space Complexity:** O(V + E) for storing edges and the Disjoint Set data structure.

### Sample Input

```text
Number of vertices: 5
Number of edges: 7

Source  Destination  Weight

0          1           2
0          3           6
1          2           3
1          3           8
1          4           5
2          4           7
3          4           9
```

### Sample Output

```text
Minimum Spanning Tree:

0 - 1 : 2
1 - 2 : 3
1 - 4 : 5
0 - 3 : 6

Minimum Cost: 16
```

## 7. Comparison of Algorithms

| Algorithm | Technique | Time Complexity |
|---|---|---|
| Fractional Knapsack | Greedy | O(n log n) |
| Job Sequencing | Greedy | O(n log n + nD) |
| Prim's Algorithm | Greedy | O(V²) |
| Kruskal's Algorithm | Greedy | O(E log E) |

## 8. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding the Greedy Method.
2. Solving optimization problems using greedy choices.
3. Implementing Fractional Knapsack.
4. Understanding Job Sequencing with Deadlines.
5. Finding Minimum Spanning Trees using Prim's Algorithm.
6. Finding Minimum Spanning Trees using Kruskal's Algorithm.
7. Understanding cycle detection and Disjoint Set Union.
8. Comparing time and space complexities of greedy algorithms.

## 9. Files in This Unit

```text
Unit-3-greedy-method/
│
├── fractionalKnapsack.cpp
├── jobScheduling.cpp
├── primsAlgorithm.cpp
├── kruskalsAlgorithm.cpp
└── README.md
```

## 10. Conclusion

This unit introduces the Greedy Method, an important algorithmic technique used to solve optimization problems by making locally optimal choices at each step.

The implementations of Fractional Knapsack, Job Sequencing with Deadlines, Prim's Algorithm, and Kruskal's Algorithm demonstrate how greedy strategies can be applied to resource allocation, scheduling, and Minimum Spanning Tree problems.

These algorithms provide a foundation for understanding optimization techniques and more advanced algorithmic problem-solving approaches.