# Graph Traversal: BFS and DFS: Technical Documentation

## 1. Introduction

**Purpose**: Implement breadth-first and depth-first graph traversals on undirected graphs.

**Problem Statement**: Different traversal orders suit different applications. BFS for shortest paths; DFS for reachability and cycle detection.

**Objectives**: Implement BFS using queue; implement DFS using recursion; compare traversal orderings; demonstrate graph algorithms.

## 2. System Overview

**Graph Representation**: Adjacency matrix where graph[i][j] = 1 indicates edge between vertices i and j.

**BFS Principle**: FIFO queue processes vertices level-by-level from source.

**DFS Principle**: Recursion explores deeply before backtracking; implicit call stack.

## 3. Functional Requirements

- Represent undirected graphs using adjacency matrix
- Implement BFS starting from given vertex
- Implement DFS starting from given vertex
- Track visited vertices to avoid revisiting
- Output traversal order

## 4. Algorithms

**BFS**: Initialize queue with start → Mark visited → While queue non-empty: dequeue vertex, enqueue unvisited neighbors → Print in order

**DFS**: Initialize visited array → Recursive function: mark visited, print vertex, recursively call for unvisited neighbors

## 5. Complexity Analysis

| Aspect | BFS | DFS |
|--------|-----|-----|
| **Time** | $O(V + E)$ | $O(V + E)$ |
| **Space** | $O(V)$ queue | $O(V)$ recursion stack |
| **Order** | Level-order | Depth-order |

## 6. Implementation Details

**Data Structures**: Adjacency matrix (2D array); queue array for BFS; visited array

**Memory**: Fixed-size arrays

**Platform**: C standard; Linux, macOS, Windows

## 7. Testing and Results

BFS and DFS correctly traverse 5-vertex graph from starting vertex; both visit all reachable vertices once.

## 8. Challenges

**BFS**: Manual queue management (front/rear pointers)

**DFS**: Recursion depth limited by system; must track visited to prevent cycles

## 9. Conclusion

Successfully implements both fundamental graph traversals. BFS optimal for unweighted shortest paths; DFS for connectivity analysis. Future: directed graphs, weighted edges, Dijkstra/Bellman-Ford.