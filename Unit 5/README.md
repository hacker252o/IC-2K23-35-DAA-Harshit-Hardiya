# Unit 5 — Traversal & Search

## 1. Overview

This unit introduces Tree Traversal and Graph Traversal techniques used to visit and process nodes in data structures.

The unit focuses on understanding Binary Tree Traversals, Graph Representation, Breadth First Search (BFS), and Depth First Search (DFS).

These algorithms are widely used in searching, pathfinding, network analysis, and solving graph-related problems.

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. **Binary Tree Traversals**
   - Inorder Traversal
   - Preorder Traversal
   - Postorder Traversal
2. **Graph Representation**
   - Adjacency Matrix
   - Adjacency List
3. **Breadth First Search (BFS)**
4. **Depth First Search (DFS)**

## 3. Binary Tree Traversals

### Problem Statement

Given a binary tree, perform different traversal operations to visit all its nodes in a specific order.

### Algorithm / Approach

Binary Tree Traversal is the process of visiting every node of a binary tree exactly once.

There are three main types of depth-first tree traversal:

1. **Inorder (Left, Root, Right):** First visit the left subtree, then the root node, and finally the right subtree.
2. **Preorder (Root, Left, Right):** First visit the root node, then the left subtree, and finally the right subtree.
3. **Postorder (Left, Right, Root):** First visit the left subtree, then the right subtree, and finally the root node.

### Pseudocode

```text
INORDER(root)

    IF root == NULL
        RETURN

    INORDER(root.left)
    PRINT root.data
    INORDER(root.right)


PREORDER(root)

    IF root == NULL
        RETURN

    PRINT root.data
    PREORDER(root.left)
    PREORDER(root.right)


POSTORDER(root)

    IF root == NULL
        RETURN

    POSTORDER(root.left)
    POSTORDER(root.right)
    PRINT root.data
```

### Complexity Analysis

| Traversal | Time Complexity |
|---|---|
| Inorder | O(n) |
| Preorder | O(n) |
| Postorder | O(n) |

**Space Complexity:** O(h) auxiliary space due to the recursive call stack, where h is the height of the tree. Worst case: O(n).

### Sample Input

```text
        1
       / \
      2   3
     / \
    4   5
```

### Sample Output

```text
Inorder:   4 2 5 1 3

Preorder:  1 2 4 5 3

Postorder: 4 5 2 3 1
```

## 4. Graph Representation

### Problem Statement

Represent a given graph using different data structures such as an Adjacency Matrix and an Adjacency List.

### Algorithm / Approach

A graph consists of vertices (nodes) and edges connecting those vertices.

There are two common ways to represent a graph:

**1. Adjacency Matrix:**

- Create a two-dimensional matrix of size V × V.
- Initialize all elements with zero.
- If an edge exists between two vertices, mark the corresponding matrix position as 1 (or store its weight).
- For an undirected graph, update both matrix positions.

**2. Adjacency List:**

- Create an array or vector of lists.
- Each index represents a vertex.
- Store all adjacent vertices in the corresponding list.
- For an undirected graph, add both vertices to each other's lists.

### Pseudocode

```text
ADJACENCY_MATRIX(V, edges)

    CREATE matrix[V][V]
    INITIALIZE all elements with 0

    FOR each edge (u, v)

        matrix[u][v] = 1
        matrix[v][u] = 1

    PRINT matrix


ADJACENCY_LIST(V, edges)

    CREATE list[V]

    FOR each edge (u, v)

        ADD v to list[u]
        ADD u to list[v]

    PRINT list
```

### Complexity Analysis

| Representation | Time Complexity |
|---|---|
| Adjacency Matrix Construction | O(V² + E) |
| Adjacency List Construction | O(V + E) |

**Space Complexity:**

- Adjacency Matrix: O(V²)
- Adjacency List: O(V + E)

### Sample Input

```text
Number of vertices: 4
Number of edges: 4

Edges:

0 1
0 2
1 2
2 3
```

### Sample Output

```text
Adjacency Matrix:

0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0


Adjacency List:

0 -> 1 2
1 -> 0 2
2 -> 0 1 3
3 -> 2
```

## 5. Breadth First Search (BFS)

### Problem Statement

Given a graph and a starting vertex, traverse all reachable vertices using Breadth First Search (BFS).

### Algorithm / Approach

Breadth First Search is a graph traversal algorithm that visits vertices level by level. It uses a Queue data structure to maintain the order of traversal.

1. Start from the given source vertex.
2. Mark the source vertex as visited.
3. Insert the source vertex into the queue.
4. Remove a vertex from the front of the queue.
5. Visit all its adjacent unvisited vertices.
6. Mark them as visited and insert them into the queue.
7. Repeat until the queue becomes empty.

### Pseudocode

```text
BFS(graph, start)

    CREATE visited array
    INITIALIZE all vertices as unvisited

    CREATE empty queue

    visited[start] = true
    PUSH start into queue

    WHILE queue is not empty

        vertex = POP front of queue

        PRINT vertex

        FOR each adjacent vertex v

            IF visited[v] == false

                visited[v] = true
                PUSH v into queue
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(V + E) |
| Average Case | O(V + E) |
| Worst Case | O(V + E) |

**Space Complexity:** O(V) for the visited array and queue.

### Sample Input

```text
Number of vertices: 5
Number of edges: 4

Edges:

0 1
0 2
1 3
1 4

Starting Vertex: 0
```

### Sample Output

```text
BFS Traversal:

0 1 2 3 4
```

## 6. Depth First Search (DFS)

### Problem Statement

Given a graph and a starting vertex, traverse all reachable vertices using Depth First Search (DFS).

### Algorithm / Approach

Depth First Search is a graph traversal algorithm that explores as far as possible along one branch before backtracking. It can be implemented using recursion or a Stack data structure.

1. Start from the given source vertex.
2. Mark the current vertex as visited.
3. Print the current vertex.
4. Visit an adjacent unvisited vertex recursively.
5. Continue exploring until no unvisited adjacent vertices remain.
6. Backtrack and explore other unvisited vertices.
7. Stop when all reachable vertices have been visited.

### Pseudocode

```text
DFS(graph, vertex, visited)

    visited[vertex] = true

    PRINT vertex

    FOR each adjacent vertex v

        IF visited[v] == false

            DFS(graph, v, visited)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(V + E) |
| Average Case | O(V + E) |
| Worst Case | O(V + E) |

**Space Complexity:** O(V) for the visited array and recursive call stack.

### Sample Input

```text
Number of vertices: 5
Number of edges: 4

Edges:

0 1
0 2
1 3
1 4

Starting Vertex: 0
```

### Sample Output

```text
DFS Traversal:

0 1 3 4 2
```

## 7. Comparison of Algorithms

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Inorder Traversal | O(n) | O(h) |
| Preorder Traversal | O(n) | O(h) |
| Postorder Traversal | O(n) | O(h) |
| Adjacency Matrix | O(V² + E) | O(V²) |
| Adjacency List | O(V + E) | O(V + E) |
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |

## 8. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding Binary Tree data structures.
2. Implementing Inorder, Preorder, and Postorder Traversals.
3. Understanding different graph representations.
4. Implementing graphs using Adjacency Matrix.
5. Implementing graphs using Adjacency List.
6. Understanding Breadth First Search (BFS).
7. Understanding Depth First Search (DFS).
8. Using Queue and Stack data structures in graph traversal.
9. Understanding recursive graph traversal.
10. Comparing time and space complexities of traversal algorithms.

## 9. Files in This Unit

```text
Unit-5-traversal-and-search/
│
├── binaryTreeTraversals.cpp
├── graphRepresentation.cpp
├── bfs.cpp
├── dfs.cpp
└── README.md
```

## 10. Conclusion

This unit introduces fundamental tree and graph traversal techniques. The implementations demonstrate how nodes and vertices can be visited systematically using different traversal strategies.

Binary Tree Traversals, Graph Representation, BFS, and DFS provide the foundation for understanding more advanced algorithms involving searching, pathfinding, and graph processing.