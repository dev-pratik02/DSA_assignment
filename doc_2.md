# Infix to Postfix Conversion and Evaluation: Technical Documentation

## 1. Introduction

**Purpose**: Convert mathematical expressions from infix notation to postfix (RPN) and evaluate using stack operations.

**Problem Statement**: Infix requires operator precedence and parentheses. Postfix eliminates precedence rules for efficient evaluation.

**Objectives**: Implement Shunting Yard algorithm; handle precedence and associativity; evaluate postfix expressions.

## 2. System Overview

**Principle**: CharStack for operators (conversion); IntStack for operands (evaluation).

**Workflow**: Parse infix → Apply precedence rules → Output postfix → Evaluate using integer stack.

## 3. Functional Requirements

- Parse infix with operators `+`, `-`, `*`, `/`, `^`, `%` and parentheses
- Handle precedence: `^` (3) > `*`, `/`, `%` (2) > `+`, `-` (1)
- Handle right-associativity for `^`
- Convert to postfix notation correctly
- Evaluate postfix expressions with single-digit operands

## 4. Non-Functional Requirements

| Requirement | Details |
|-------------|---------|
| **Time Complexity** | $O(n)$ conversion; $O(n)$ evaluation |
| **Space Complexity** | $O(n)$ both stacks |
| **Operators** | `+`, `-`, `*`, `/`, `%`, `^` |
| **Constraints** | Max 100 chars; single-digit operands |

## 5. System Design

**Data Structures**:
- **CharStack**: Operators and parentheses
- **IntStack**: Operands and results

**Algorithm** (Shunting Yard):
1. Operand → output
2. `(` → push
3. `)` → pop until `(`
4. Operator → pop higher/equal precedence respecting associativity, push current

## 6. Function Description

**Stack Operations**: `initCharStack()`, `isCharStackEmpty()`, `pushChar()`, `popChar()`, `peekChar()` - $O(1)$

**Helpers**: `isOperator()`, `getPrecedence()`, `isRightAssociative()` - classify operators

**Conversion**: `infixToPostfix()` - applies Shunting Yard algorithm - $O(n)$

**Evaluation**: `performOperation()` (arithmetic), `evaluatePostfix()` (postfix evaluation) - $O(n)$

## 7. Implementation Details

**Libraries**: `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`, `stdbool.h`, `math.h`

**Precedence**: `^` (level 3, right-associative); `*`, `/`, `%` (level 2); `+`, `-` (level 1)

**Platform**: Linux, macOS, Windows; C99+

## 8. Testing and Results

| Test | Infix | Postfix | Result |
|------|-------|---------|--------|
| 1 | `3+4*2` | `342*+` | 11 |
| 2 | `(3+4)*2` | `34+2*` | 14 |
| 3 | `2^3^2` | `232^^` | 512 |

**Output**: Correct conversion and evaluation for all cases.

## 9. Challenges and Limitations

**Challenges**: Operator precedence/associativity; nested parentheses; right-associative operator handling.

**Limitations**: Single-digit operands only; no variables; no multi-char operators; no error recovery.

## 10. Conclusion

Successfully implements Shunting Yard algorithm for infix-to-postfix conversion and RPN evaluation. Demonstrates stack operations, operator precedence, and associativity rules. Future: support multi-digit numbers, floating-point, variables.
