# Heap Construction: Technical Documentation

## 1. Introduction

**Purpose**: Build min and max heaps from unsorted arrays using heapification.

**Problem Statement**: Heaps enable efficient priority queues and heap sort. Construction must respect heap property.

**Objectives**: Implement minHeapify and maxHeapify; build min and max heaps in $O(n)$ time; demonstrate heap property maintenance.

## 2. System Overview

**Heap Principle**: Complete binary tree stored in array; parent at i, left child at 2i+1, right child at 2i+2.

**Heap Property**: Min heap: parent ≤ children; Max heap: parent ≥ children.

**Construction**: Apply heapify bottom-up from n/2-1 to 0.

## 3. Data Structures

```c
// Array-based representation
int arr[MAX_SIZE];
// For node at index i:
// Left = 2i+1; Right = 2i+2; Parent = (i-1)/2
```

## 4. Algorithms

**minHeapify(arr, n, i)**:
1. Find smallest among i, left child, right child
2. If smallest ≠ i, swap and recursively heapify

**buildMinHeap(arr, n)**:
1. Start from index n/2-1 (last non-leaf)
2. Apply minHeapify for each parent going backward

**Time**: $O(n)$ (not $O(n \log n)$); **Space**: $O(1)$ excluding output

## 5. Functions

**swap()**: Exchange two integer values

**minHeapify()/maxHeapify()**: Recursive functions maintaining heap property

**buildMinHeap()/buildMaxHeap()**: Convert array to respective heap

## 6. Implementation Details

**Libraries**: stdio.h

**Platform**: C standard; all operating systems

**Memory**: In-place heap building

## 7. Testing and Results

Both heaps correctly constructed from unsorted array; heap properties verified.

## 8. Limitations

Fixed array size; no dynamic resizing; no insertion/deletion; heapify assumes child subtrees are already valid.

## 9. Conclusion

Successfully implements heap construction for both min and max configurations. Foundation for priority queues and heap sort. Future: dynamic heap with insert/delete.