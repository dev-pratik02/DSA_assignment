# Sorting Algorithms Comparison: Technical Documentation

## 1. Introduction

**Purpose**: Compare sorting algorithms' performance via operation counts (comparisons and swaps).

**Problem Statement**: Different algorithms have varied efficiency. Performance analysis guides algorithm selection for applications.

**Objectives**: Implement four sorting algorithms; instrument with counters; compare empirical costs; analyze complexity.

## 2. System Overview

**Metric**: Track comparisons and swaps to evaluate real-world performance beyond Big-O analysis.

**Workflow**: Generate random array → User selects algorithm → Sort and count → Display sorted array and statistics.

## 3. Algorithms Implemented

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable |
|-----------|-----------|--------------|-----------|-------|--------|
| Bubble Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| Selection | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | No |
| Insertion | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| Merge Sort | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes |

## 4. Functional Requirements

- Accept user-selected algorithm (1-4)
- Generate random integers [1, 1000]
- Sort array and count operations
- Display original/sorted arrays and statistics

## 5. Functions

**resetCounters()**: Set comparisons/swaps to zero

**bubbleSort()**: Nested loops comparing adjacent elements; $O(n^2)$ worst case

**selectionSort()**: Find minimum, swap; $O(n^2)$ always

**insertionSort()**: Shift and insert; $O(n^2)$ worst

**mergeSort()**: Divide-conquer; $O(n \log n)$ always

## 6. Implementation Details

**Libraries**: stdio.h, stdlib.h, time.h, stdbool.h

**Random Generation**: time(0) seed; rand() % 1000

**Counters**: Global comparisons and swaps tracked per algorithm

**Platform**: C standard

## 7. Testing and Results

All four algorithms correctly sort arrays; counters accurately reflect operational costs; merge sort shows superior performance for large inputs.

## 8. Observed Complexity

Empirical counts validate theoretical analysis: bubble/selection $O(n^2)$; insertion $O(n^2)$ average; merge $O(n \log n)$.

## 9. Limitations

Fixed array size; in-place except merge sort; no adaptive optimizations; single run (no averaging).

## 10. Conclusion

Successfully compares four fundamental sorting algorithms through empirical analysis. Demonstrates that Big-O provides useful but incomplete performance picture. Future: implement quicksort, heapsort, parallel sorts, adaptive variants.



