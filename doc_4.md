# Doubly Linked List Operations: Technical Documentation

## 1. Introduction

**Purpose**: Implement doubly linked list with insert and delete operations maintaining bidirectional navigation.

**Problem Statement**: Single-linked lists require traversal from head. Doubly-linked enable backward navigation and efficient modifications.

**Objectives**: Implement insertAfter(); implement deleteNode(); maintain both forward and backward pointers; demonstrate pointer manipulation.

## 2. System Overview

**Principle**: Each node maintains both prev and next pointers for bidirectional traversal.

**Workflow**: Locate node → Create/remove entry → Update four pointers (or two for boundary cases).

## 3. Data Structures

```c
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
```

## 4. Functional Requirements

- Insert node after given node (maintain both pointers)
- Delete node with specific data value
- Handle boundary conditions (head/tail)
- Support null pointer checks

## 5. Core Operations

**insertAfter(Node *prevNode, int newData)**:
1. Allocate new node
2. Set new→prev = prevNode; new→next = prevNode→next
3. Update prevNode→next = new
4. If prevNode→next exists, set its prev = new

**deleteNode(Node **head, int data)**:
1. Search for node with data
2. Update D→prev→next = D→next (if prev exists)
3. Update D→next→prev = D→prev (if next exists)
4. If D is head: head = D→next
5. Free memory

## 6. Complexity Analysis

**Time**: $O(n)$ search operations
**Space**: $O(1)$ excluding output

## 7. Implementation Details

**Memory**: Dynamic allocation; manual free()

**Platform**: C standard

## 8. Testing and Results

Pointer integrity maintained; bidirectional traversal correct.

## 9. Limitations

No search optimization; manual memory management.

## 10. Conclusion

Successfully demonstrates doubly-linked list fundamentals essential for advanced data structures.

