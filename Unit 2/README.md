# Unit 02 – Divide and Conquer

## 1. Overview

This unit introduces the Divide and Conquer approach and recursive techniques for solving searching and sorting problems. The programs included in this unit demonstrate Binary Search, Merge Sort, Quick Sort, and recursive implementations of Bubble Sort and Insertion Sort.

The unit focuses on breaking a problem into smaller parts, solving those parts recursively or independently, and combining the results where required.

## 2. Algorithms Implemented

The following algorithms are implemented in this unit:

1. Iterative Binary Search
2. Recursive Binary Search
3. Merge Sort
4. Quick Sort
5. Recursive Bubble Sort
6. Recursive Insertion Sort
7. Heap Sort
8. Strassen Matrix Multiplication

## 3. Iterative Binary Search

### Problem Statement

Given a sorted array and a target value, find the position of the target element using Binary Search without recursion.

### Algorithm / Approach

Binary Search repeatedly divides the search range into two halves. The middle element is compared with the target. If the target is larger, the left boundary is moved to the right half; otherwise, the right boundary is moved to the left half.

### Pseudocode

```text
BINARY_SEARCH(array, target)

    left = 0
    right = n - 1

    WHILE left <= right

        mid = left + (right - left) / 2

        IF array[mid] == target
            RETURN mid

        IF array[mid] < target
            left = mid + 1

        ELSE
            right = mid - 1

    RETURN -1
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

**Space Complexity:** O(1)

### Sample Input

```text
Array: 10 20 30 40 50 60 70
Target: 40
```

### Sample Output

```text
Element found at index: 3
```

## 4. Recursive Binary Search

### Problem Statement

Given a sorted array and a target value, find the position of the target element using Binary Search recursively.

### Algorithm / Approach

The array is divided into two halves at every recursive call. The middle element is compared with the target, and only the half that can contain the target is searched further.

### Pseudocode

```text
RECURSIVE_BINARY_SEARCH(array, left, right, target)

    IF left > right
        RETURN -1

    mid = left + (right - left) / 2

    IF array[mid] == target
        RETURN mid

    IF array[mid] < target
        RETURN RECURSIVE_BINARY_SEARCH(array, mid + 1, right, target)

    RETURN RECURSIVE_BINARY_SEARCH(array, left, mid - 1, target)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |

**Space Complexity:** O(log n) due to the recursive call stack.

### Sample Input

```text
Array: 10 20 30 40 50 60 70
Target: 40
```

### Sample Output

```text
Element found at index: 3
```

## 5. Merge Sort

### Problem Statement

Sort the given array in ascending order using the Merge Sort algorithm.

### Algorithm / Approach

Merge Sort follows the Divide and Conquer approach. The array is repeatedly divided into two halves until single-element subarrays are obtained. The sorted subarrays are then merged to produce the final sorted array.

### Pseudocode

```text
MERGE_SORT(array, left, right)

    IF left >= right
        RETURN

    mid = left + (right - left) / 2

    MERGE_SORT(array, left, mid)
    MERGE_SORT(array, mid + 1, right)

    MERGE(array, left, mid, right)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |

**Space Complexity:** O(n)

### Sample Input

```text
38 27 43 3 9 82 10
```

### Sample Output

```text
3 9 10 27 38 43 82
```

## 6. Quick Sort

### Problem Statement

Sort the given array in ascending order using the Quick Sort algorithm.

### Algorithm / Approach

Quick Sort selects a pivot element and partitions the array so that elements smaller than the pivot are placed before it and larger elements are placed after it. The two resulting parts are then sorted recursively.

The implementation in this unit uses the last element as the pivot.

### Pseudocode

```text
QUICK_SORT(array, low, high)

    IF low >= high
        RETURN

    pivotIndex = PARTITION(array, low, high)

    QUICK_SORT(array, low, pivotIndex - 1)
    QUICK_SORT(array, pivotIndex + 1, high)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n²) |

**Space Complexity:** O(log n) on average due to recursion, and O(n) in the worst case.

### Sample Input

```text
10 7 8 9 1 5
```

### Sample Output

```text
1 5 7 8 9 10
```

## 7. Recursive Bubble Sort

### Problem Statement

Sort an array in ascending order using a recursive version of the Bubble Sort algorithm.

### Algorithm / Approach

One complete Bubble Sort pass moves the largest element of the current unsorted portion to the end. The algorithm then recursively sorts the remaining portion of the array.

The implementation also stops early if no swapping occurs during a pass.

### Pseudocode

```text
RECURSIVE_BUBBLE_SORT(array, n)

    IF n <= 1
        RETURN

    swapped = false

    FOR i = 0 to n - 2

        IF array[i] > array[i + 1]
            SWAP array[i] and array[i + 1]
            swapped = true

    IF swapped == false
        RETURN

    RECURSIVE_BUBBLE_SORT(array, n - 1)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |

**Space Complexity:** O(n) due to the recursive call stack.

### Sample Input

```text
64 34 25 12 22 11 90
```

### Sample Output

```text
11 12 22 25 34 64 90
```

## 8. Recursive Insertion Sort

### Problem Statement

Sort an array in ascending order using a recursive version of the Insertion Sort algorithm.

### Algorithm / Approach

The algorithm recursively sorts the first n - 1 elements. It then takes the last element and inserts it into its correct position in the already sorted portion.

### Pseudocode

```text
RECURSIVE_INSERTION_SORT(array, n)

    IF n <= 1
        RETURN

    RECURSIVE_INSERTION_SORT(array, n - 1)

    key = array[n - 1]
    j = n - 2

    WHILE j >= 0 AND array[j] > key

        array[j + 1] = array[j]
        j = j - 1

    array[j + 1] = key
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |

**Space Complexity:** O(n) due to the recursive call stack.

### Sample Input

```text
12 11 13 5 6
```

### Sample Output

```text
5 6 11 12 13
```

## 9. Heap Sort

### Problem Statement

Given an unsorted array of elements, sort the array in ascending order using the Heap Sort algorithm.

### Algorithm / Approach

Heap Sort uses a Binary Heap data structure to sort elements. It works in two phases:

1. **Build Max Heap:** Convert the given array into a Max Heap, where the parent node is always greater than or equal to its children.
2. **Sorting:** Swap the root element (largest element) with the last element of the heap. Reduce the heap size by one and apply the heapify operation to maintain the Max Heap property. Repeat until the entire array is sorted.

### Pseudocode

```text
HEAP_SORT(array, n)

    // Build Max Heap
    FOR i = n/2 - 1 DOWNTO 0
        HEAPIFY(array, n, i)

    // Extract elements one by one
    FOR i = n - 1 DOWNTO 1

        SWAP(array[0], array[i])

        HEAPIFY(array, i, 0)


HEAPIFY(array, n, i)

    largest = i
    left = 2*i + 1
    right = 2*i + 2

    IF left < n AND array[left] > array[largest]
        largest = left

    IF right < n AND array[right] > array[largest]
        largest = right

    IF largest != i
        SWAP(array[i], array[largest])

        HEAPIFY(array, n, largest)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |

**Space Complexity:** O(log n) auxiliary space due to recursive heapify calls. O(1) if iterative heapify is used.

### Sample Input

```text
Array: 12 11 13 5 6 7
```

### Sample Output

```text
Sorted Array: 5 6 7 11 12 13
```

## 10. Strassen Matrix Multiplication

### Problem Statement

Given two square matrices of order n × n, multiply them using Strassen's Matrix Multiplication algorithm to obtain the resultant matrix.

### Algorithm / Approach

Strassen's Matrix Multiplication is a divide-and-conquer algorithm used to multiply two matrices efficiently. It divides both matrices into four equal-sized submatrices and performs seven recursive multiplications instead of the eight multiplications required by conventional matrix multiplication.

The algorithm works in the following steps:

1. **Divide:** Divide both matrices into four equal-sized submatrices.
2. **Calculate:** Compute seven products (P1 to P7) using matrix addition and subtraction.
3. **Combine:** Use these seven products to calculate the four submatrices of the resultant matrix.
4. **Repeat:** Continue recursively until the matrix size becomes 1 × 1.

### Pseudocode

```text
STRASSEN(A, B, n)

    IF n == 1
        RETURN A[0][0] * B[0][0]

    Divide A into:
        A11, A12
        A21, A22

    Divide B into:
        B11, B12
        B21, B22

    P1 = STRASSEN(A11, B12 - B22)
    P2 = STRASSEN(A11 + A12, B22)
    P3 = STRASSEN(A21 + A22, B11)
    P4 = STRASSEN(A22, B21 - B11)
    P5 = STRASSEN(A11 + A22, B11 + B22)
    P6 = STRASSEN(A12 - A22, B21 + B22)
    P7 = STRASSEN(A11 - A21, B11 + B12)

    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7

    Combine C11, C12, C21, C22

    RETURN C
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best Case | O(n^2.807) |
| Average Case | O(n^2.807) |
| Worst Case | O(n^2.807) |

**Space Complexity:** O(n²) auxiliary space for storing intermediate matrices (implementation-dependent).

### Sample Input

```text
Matrix A:
1 2
3 4

Matrix B:
5 6
7 8
```

### Sample Output

```text
Resultant Matrix:
19 22
43 50
```

## 11. Comparison of Algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space |
|---|---|---|---|---|
| Iterative Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Recursive Binary Search | O(1) | O(log n) | O(log n) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n)* |
| Recursive Bubble Sort | O(n) | O(n²) | O(n²) | O(n) |
| Recursive Insertion Sort | O(n) | O(n²) | O(n²) | O(n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(log n)** |
| Strassen Matrix Multiplication | O(n^2.807) | O(n^2.807) | O(n^2.807) | O(n²)*** |

*Quick Sort uses O(log n) auxiliary stack space on average and can require O(n) stack space in the worst case.

**Heap Sort uses O(log n) auxiliary space with recursive heapify and O(1) with iterative heapify.

***Strassen's auxiliary space depends on the implementation and matrix storage strategy.

## 12. Learning Outcomes

After completing this unit, the following concepts were studied:

1. Understanding the Divide and Conquer approach.
2. Understanding recursive problem solving.
3. Implementation of Binary Search using iterative and recursive approaches.
4. Implementation of Merge Sort.
5. Implementation of Quick Sort.
6. Understanding partitioning and pivot selection in Quick Sort.
7. Converting iterative sorting algorithms into recursive implementations.
8. Understanding recursion and the call stack.
9. Comparing time and space complexity.
10. Understanding best, average, and worst-case complexity.
11. Understanding Heap Sort and Binary Heap operations.
12. Understanding Strassen Matrix Multiplication.
13. Implementing algorithms using C++.

## 13. Files in This Unit

```text
Unit-2-divide-and-conquer/
│
├── iterativeBinarySearch.cpp
├── mergeSort.cpp
├── quickSort.cpp
├── recursiveBinarySearch.cpp
├── recursiveBubbleSort.cpp
├── recursiveInsertionSort.cpp
├── heapSort.cpp
├── strassenMatrixMultiplication.cpp
└── README.md
```

## 14. Conclusion

This unit introduces Divide and Conquer and recursive approaches for solving searching and sorting problems. The implementations demonstrate how a problem can be divided into smaller parts and solved efficiently using recursion.

Binary Search, Merge Sort, and Quick Sort provide important examples of Divide and Conquer, while the recursive Bubble Sort and Insertion Sort implementations help develop a deeper understanding of recursion and recursive problem solving.

Heap Sort and Strassen Matrix Multiplication further demonstrate the use of efficient data structures and divide-and-conquer techniques in algorithm design.