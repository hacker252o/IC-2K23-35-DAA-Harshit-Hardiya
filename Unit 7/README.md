# Unit 7 — NP-Hard / NP-Complete

## 1. Overview

This unit introduces the concepts of NP-Hard and NP-Complete problems along with different algorithmic techniques used to solve computationally difficult problems.

The unit focuses on understanding Exhaustive Search, Branch and Bound, the 0/1 Knapsack Problem, and the Travelling Salesman Problem (TSP).

These techniques are widely used in optimization, decision-making, resource allocation, scheduling, and solving complex computational problems.

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. **Exhaustive Search**
   - Generating and checking all possible solutions.
   - Selecting the solution that satisfies the given conditions.
   - Understanding brute-force problem-solving techniques.

2. **Branch and Bound**
   - Dividing a problem into smaller subproblems.
   - Calculating bounds to estimate possible solutions.
   - Eliminating branches that cannot produce a better solution.

3. **0/1 Knapsack Problem**
   - Selecting items with given weights and values.
   - Maximizing total value without exceeding the capacity.
   - Using Branch and Bound or other suitable approaches.

4. **Travelling Salesman Problem (TSP)**
   - Finding the shortest possible route visiting every city exactly once.
   - Returning to the starting city.
   - Minimizing the total travelling cost.

## 3. Exhaustive Search

### Problem Statement

Given a problem with multiple possible solutions, examine every possible candidate solution to find the correct or optimal solution.

The objective is to understand how exhaustive search explores the entire solution space to identify the required answer.

### Algorithm / Approach

Exhaustive Search, also known as Brute Force, is a problem-solving technique that checks all possible solutions.

1. Generate all possible candidate solutions.
2. Check whether each candidate satisfies the given conditions.
3. Calculate the cost or value of each valid solution, if required.
4. Compare the candidate solutions.
5. Select the valid solution with the best result.
6. Continue until all possible solutions have been examined.

### Pseudocode

**EXHAUSTIVE_SEARCH(candidates)**

    bestSolution = NULL
    bestValue = INITIAL_VALUE

    FOR each candidate in candidates

        IF candidate is valid

            value = CALCULATE_VALUE(candidate)

            IF value is better than bestValue
                bestValue = value
                bestSolution = candidate

    RETURN bestSolution

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(2^N) |
| Average Case | O(2^N) |
| Worst Case | O(2^N) |

**Space Complexity:** Depends on the problem and implementation. It can be O(N) when candidates are generated recursively.

### Sample Input

    Number of elements: 3

    Elements:
    1 2 3

### Sample Output

**All Possible Subsets:**

    {}
    {1}
    {2}
    {3}
    {1, 2}
    {1, 3}
    {2, 3}
    {1, 2, 3}

## 4. Branch and Bound

### Problem Statement

Given an optimization problem, find the optimal solution by systematically exploring possible solutions while eliminating branches that cannot produce a better result.

### Algorithm / Approach

Branch and Bound is an optimization technique that divides a problem into smaller subproblems and uses bounds to avoid unnecessary calculations.

1. Start with the initial problem.
2. Divide the problem into smaller subproblems (Branching).
3. Calculate an upper bound or lower bound for each subproblem.
4. Compare the calculated bound with the current best solution.
5. Eliminate branches that cannot produce a better solution (Pruning).
6. Continue exploring the promising branches.
7. Update the best solution whenever a better solution is found.
8. Stop when no promising branches remain.

### Pseudocode

**BRANCH_AND_BOUND(problem)**

    CREATE priority queue
    INSERT initial problem into queue

    bestSolution = INITIAL_VALUE

    WHILE queue is not empty

        node = REMOVE most promising node

        IF BOUND(node) cannot improve bestSolution
            CONTINUE

        IF node is a complete solution
            UPDATE bestSolution
        ELSE
            GENERATE child nodes

            FOR each child
                IF child is promising
                    INSERT child into queue

    RETURN bestSolution

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | Depends on pruning |
| Average Case | Problem-dependent |
| Worst Case | Exponential |

**Space Complexity:** Can be exponential in the worst case because multiple unexplored nodes may be stored in the priority queue.

### Sample Input

    Number of items: 3

    Item values:
    60 100 120

    Item weights:
    10 20 30

    Knapsack Capacity: 50

### Sample Output

    Maximum Profit: 220

    Selected Items:
    Item 2
    Item 3

## 5. 0/1 Knapsack Problem

### Problem Statement

Given N items, each having a weight and a value, and a knapsack with a fixed capacity, select items to maximize the total value without exceeding the capacity.

Each item can either be selected completely (1) or not selected (0). An item cannot be divided.

### Algorithm / Approach

The 0/1 Knapsack Problem can be solved using different techniques, including Dynamic Programming and Branch and Bound.

In this unit, the problem can be approached using Branch and Bound.

1. Start with an empty knapsack.
2. Calculate the value-to-weight ratio of each item.
3. Sort items according to their value-to-weight ratio when using a fractional upper-bound calculation.
4. Consider including or excluding the next item.
5. Calculate the upper bound of each resulting branch.
6. Eliminate branches that exceed capacity or cannot improve the current maximum profit.
7. Explore promising branches.
8. Update the maximum profit whenever a better valid solution is found.

### Pseudocode

**KNAPSACK(items, capacity)**

    maximumProfit = 0

    CREATE priority queue
    INSERT initial node into queue

    WHILE queue is not empty

        node = REMOVE most promising node

        IF node.bound <= maximumProfit
            CONTINUE

        GENERATE include and exclude branches

        FOR each child node

            IF child.weight <= capacity

                IF child.profit > maximumProfit
                    maximumProfit = child.profit

                IF child.bound > maximumProfit
                    INSERT child into queue

    RETURN maximumProfit

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | Depends on pruning |
| Average Case | Problem-dependent |
| Worst Case | O(2^N) |

**Space Complexity: O(2^N)** in the worst case for storing unexplored nodes.

### Sample Input

    Number of items: 3

    Item 1: Weight = 10, Value = 60
    Item 2: Weight = 20, Value = 100
    Item 3: Weight = 30, Value = 120

    Knapsack Capacity: 50

### Sample Output

    Maximum Profit: 220

    Selected Items:
    Item 2
    Item 3

## 6. Travelling Salesman Problem (TSP)

### Problem Statement

Given a set of cities and the distances between them, find the shortest possible route that visits every city exactly once and returns to the starting city.

The objective is to minimize the total travelling distance or cost.

### Algorithm / Approach

The Travelling Salesman Problem can be solved using Exhaustive Search or Branch and Bound.

Using Branch and Bound:

1. Start from the initial city.
2. Generate possible paths to unvisited cities.
3. Calculate the cost of each partial path.
4. Estimate a lower bound for completing each path.
5. Compare the lower bound with the current minimum tour cost.
6. Eliminate branches that cannot produce a shorter tour.
7. Continue exploring promising paths.
8. Return to the starting city after visiting all other cities.
9. Update the minimum tour cost whenever a better complete route is found.

### Pseudocode

**TSP_BRANCH_AND_BOUND(graph, start)**

    minimumCost = INFINITY

    CREATE priority queue
    INSERT initial node into queue

    WHILE queue is not empty

        node = REMOVE node with minimum bound

        IF node.bound >= minimumCost
            CONTINUE

        IF all cities have been visited

            totalCost = node.cost +
                        cost of returning to start

            IF totalCost < minimumCost
                minimumCost = totalCost

        ELSE

            FOR each unvisited city

                GENERATE new path
                CALCULATE new cost
                CALCULATE lower bound

                IF new bound < minimumCost
                    INSERT new node into queue

    RETURN minimumCost

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | Depends on pruning |
| Average Case | Problem-dependent |
| Worst Case | O(N!) |

**Space Complexity: O(N!)** in the worst case, depending on the number of unexplored nodes stored.

### Sample Input

    Number of cities: 4

    Cost Matrix:

    0  10  15  20
    10  0  35  25
    15 35  0  30
    20 25 30  0

    Starting City: 0

### Sample Output

    Minimum Tour Cost: 80

    Optimal Tour:
    0 -> 1 -> 3 -> 2 -> 0

## 7. Comparison of Algorithms

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Exhaustive Search | O(2^N) for subset enumeration | Problem-dependent |
| Branch and Bound | Exponential in worst case | Exponential in worst case |
| 0/1 Knapsack (B&B) | O(2^N) | O(2^N) |
| TSP (B&B) | O(N!) | O(N!) |

## 8. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding NP-Hard and NP-Complete problems.
2. Understanding computationally difficult problems.
3. Understanding the Exhaustive Search technique.
4. Exploring all possible candidate solutions using brute force.
5. Understanding the Branch and Bound technique.
6. Understanding branching and pruning operations.
7. Implementing the 0/1 Knapsack Problem.
8. Understanding item selection based on weight and value.
9. Maximizing profit under a given capacity constraint.
10. Understanding the Travelling Salesman Problem.
11. Finding an optimal route between multiple cities.
12. Applying optimization techniques to complex problems.
13. Comparing the time and space complexities of different algorithms.

## 9. Files in This Unit

    Unit-7-np-hard-np-complete/
    │
    ├── exhaustiveSearch.cpp
    ├── branchAndBound.cpp
    ├── knapsack.cpp
    ├── tsp.cpp
    └── README.md

## 10. Conclusion

This unit introduces important concepts related to NP-Hard and NP-Complete problems and demonstrates different techniques for solving computationally difficult problems.

The implementations of Exhaustive Search, Branch and Bound, 0/1 Knapsack, and Travelling Salesman Problem demonstrate how possible solutions can be explored, evaluated, and optimized.

These algorithms provide a foundation for understanding computational complexity, optimization techniques, and advanced problem-solving approaches used in computer science.