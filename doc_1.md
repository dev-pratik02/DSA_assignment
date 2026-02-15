# Parentheses Balancing Verification: Technical Documentation

## 1. Introduction

**Purpose**: Verify balance and proper nesting of parentheses, brackets, and braces in mathematical expressions and code sequences. Essential for syntax validation in compilers and interpreters.

**Problem Statement**: Unbalanced delimiters cause syntax errors. The challenge is efficiently validating multiple bracket types while handling proper nesting.

**Objectives**: Implement stack-based bracket validation algorithm; handle `()`, `[]`, `{}`; identify mismatches and improper nesting; demonstrate DSA principles.

## 2. System Overview

**System Principle**: Balanced expressions follow LIFO pattern. Opening brackets are pushed onto stack; closing brackets validated against the top element.

**Workflow**: Input → Initialize Stack → Sequential Processing (push opening, validate closing) → Verify Empty Stack → Output Result

## 3. Functional Requirements

- Stack management (init, push, pop, peek with overflow/underflow detection)
- Delimiter recognition and classification
- Character-by-character expression processing
- Correct nesting order maintenance
- Clear balanced/unbalanced output

## 4. Non-Functional Requirements

| Requirement | Details |
|-------------|---------|
| **Time Complexity** | $O(n)$ - single pass through expression |
| **Space Complexity** | $O(n)$ worst case (all opening brackets) |
| **Constraints** | Max 100 characters; fixed stack capacity |
| **Reliability** | Graceful underflow/overflow handling |

## 5. System Design

**Architecture**: Data Structure Layer → Operation Layer → Validation Layer → Processing Layer → Interface Layer

**Data Structure**:
```c
typedef struct {
    char data[MAX_SIZE];  // Bracket characters
    int top;              // -1 when empty
} Stack;
```

**Design Rationale**: Array-based $O(1)$ operations; character array optimizes memory; integer top pointer manages state efficiently.

## 6. Function Description

**Stack Operations**: `initStack()`, `isEmpty()`, `isFull()`, `push()`, `pop()`, `peek()` - all $O(1)$

**Classification Functions**: `isOpeningBracket()`, `isClosingBracket()`, `isMatchingPair()` - recognize and validate bracket types

**Core Algorithm** `areParenthesesBalanced()`: Initialize stack → iterate characters → push opening brackets → validate closing brackets against stack top → return true only if stack empty at end. $O(n)$ time, $O(k)$ space (k = opening brackets).

**UI Functions**: `checkAndDisplay()` - validates and outputs result; `main()` - executes three test cases

## 7. Implementation Details

**Libraries**: `stdio.h` (I/O), `stdlib.h` (utilities), `string.h` (strlen), `stdbool.h` (bool type)

**Compiler**: GCC/C99+ compatible

**Platform**: Linux, macOS, Windows; minimal memory (~400 bytes)

## 8. Testing and Results

| Test | Input | Result | Reason |
|------|-------|--------|--------|
| 1 | `a + (b - c) * (d` | Unbalanced | Missing closing `)` |
| 2 | `m + [a - b * (c + d * {m)]` | Unbalanced | Mismatched `{` with `)` |
| 3 | `a + (b - c)` | Balanced | Proper matching |

**Output**: All tests passed correctly identifying balanced vs. unbalanced states.

## 9. Challenges and Limitations

**Challenges**: Multiple bracket types require matching logic; LIFO naturally handles nesting validation; early termination saves processing.

**Limitations**: Fixed 100-char limit; no error location reporting; static memory allocation; ignores non-bracket characters.

## 10. Conclusion

Successfully implements linear-time bracket validation using stack. Demonstrates stack operations, proper abstraction, and edge case handling. Future improvements: dynamic allocation, error reporting, file input, operator validation.

