# Unit 6 — Backtracking

## 1. Overview

This unit introduces the Backtracking technique used to solve problems by exploring different possible solutions and eliminating those that do not satisfy the required conditions.

The unit focuses on understanding and implementing the N-Queens Problem and Sum of Subsets Problem.

Backtracking is widely used in constraint satisfaction problems, combinatorial optimization, puzzles, and problems involving searching through multiple possible solutions.

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. **N-Queens Problem**
   - Placing N queens on an N × N chessboard.
   - Ensuring that no two queens attack each other.
   - Using recursive backtracking to find valid arrangements.

2. **Sum of Subsets Problem**
   - Finding subsets whose elements add up to a given target sum.
   - Using recursive backtracking to explore possible combinations.
   - Eliminating branches that cannot produce a valid solution.

## 3. N-Queens Problem

### Problem Statement

Given an N × N chessboard, place N queens on the board such that no two queens attack each other.

A queen can attack another queen if they are in the same row, column, or diagonal.

The objective is to find all possible valid arrangements of N queens on the chessboard.

### Algorithm / Approach

The N-Queens Problem is solved using the Backtracking technique.

1. Start from the first row of the chessboard.
2. Try placing a queen in each column of the current row.
3. Check whether the position is safe.
4. A position is safe if no previously placed queen exists in the same column or diagonal.
5. If the position is safe, place the queen and move to the next row.
6. If no safe position is available, backtrack to the previous row and change the queen's position.
7. Repeat until all N queens are successfully placed.
8. Print the valid arrangement.

### Pseudocode

**NQUEENS(board, row, N)**

    IF row == N
        PRINT board
        RETURN

    FOR col = 0 TO N - 1
        IF IS_SAFE(board, row, col, N)
            board[row][col] = 1

            NQUEENS(board, row + 1, N)

            board[row][col] = 0

**IS_SAFE(board, row, col, N)**

    CHECK same column in previous rows

    CHECK upper-left diagonal

    CHECK upper-right diagonal

    IF no queen is found
        RETURN true

    RETURN false

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(N!) |
| Average Case | O(N!) |
| Worst Case | O(N!) |

**Space Complexity: O(N²)** for the chessboard and O(N) for the recursive call stack.

### Sample Input

    Enter number of queens: 4

### Sample Output

**One Possible Solution:**

    0 0 1 0
    1 0 0 0
    0 0 0 1
    0 1 0 0

Here, 1 represents a queen and 0 represents an empty cell.

The program can generate multiple valid arrangements.

## 4. Sum of Subsets Problem

### Problem Statement

Given a set of positive integers and a target sum, find all subsets whose elements add up to the given target value.

The objective is to identify all possible combinations of elements that produce the required sum using the Backtracking technique.

### Algorithm / Approach

The Sum of Subsets Problem is solved using recursive backtracking.

1. Start with an empty subset and a current sum of zero.
2. Consider the first element of the given set.
3. Include the current element in the subset and update the current sum.
4. Check whether the current sum equals the target sum.
5. If the target is reached, print the current subset.
6. If the current sum exceeds the target, backtrack.
7. Otherwise, explore the possibility of excluding the current element.
8. Continue until all possible combinations have been explored.

### Pseudocode

**SUM_OF_SUBSETS(arr, index, currentSum, target)**

    IF currentSum == target
        PRINT selected subset
        RETURN

    IF index == N OR currentSum > target
        RETURN

    INCLUDE arr[index] in subset

    SUM_OF_SUBSETS(arr, index + 1,
                   currentSum + arr[index], target)

    REMOVE arr[index] from subset

    EXCLUDE arr[index]

    SUM_OF_SUBSETS(arr, index + 1,
                   currentSum, target)

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(2^N) |
| Average Case | O(2^N) |
| Worst Case | O(2^N) |

**Space Complexity: O(N)** for the recursive call stack and the selected subset, excluding the space required to store all printed solutions.

### Sample Input

    Number of elements: 5

    Elements:
    1 2 3 4 5

    Target Sum: 5

### Sample Output

**Subsets with the given sum:**

    1 4
    2 3
    5

## 5. Comparison of Algorithms

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| N-Queens | O(N!) | O(N²) |
| Sum of Subsets | O(2^N) | O(N) |

## 6. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding the Backtracking technique.
2. Understanding recursive problem-solving approaches.
3. Implementing the N-Queens Problem.
4. Understanding the conditions required for safe queen placement.
5. Checking rows, columns, and diagonals in the N-Queens Problem.
6. Understanding the Sum of Subsets Problem.
7. Finding subsets that satisfy a given target sum.
8. Understanding inclusion and exclusion of elements.
9. Using recursion to explore possible solutions.
10. Understanding pruning and backtracking.
11. Comparing the time and space complexities of backtracking algorithms.

## 7. Files in This Unit

    Unit-6-backtracking/
    │
    ├── nQueens.cpp
    ├── sumOfSubsets.cpp
    └── README.md

## 8. Conclusion

This unit introduces the fundamental concept of Backtracking, a powerful algorithmic technique used to solve problems involving multiple possible solutions and constraints.

The implementations of the N-Queens Problem and Sum of Subsets Problem demonstrate how recursion, decision-making, and backtracking can be used to explore possible solutions systematically.

These algorithms provide a foundation for understanding more advanced problems involving combinatorial search, constraint satisfaction, and optimization.