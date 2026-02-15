#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

//structure for stack
typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

// Initialization of the stack
void initStack(Stack *s)
{
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack *s)
{
    return s->top == -1;
}

// Check if stack is full
bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Push a character onto the stack
void push(Stack *s, char ch)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
    }
    else
    {
        s->data[++(s->top)] = ch;
    }
   
}

// Pop a character from the stack
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Get the top character without removing it
char peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}

// Check if a character is an opening bracket
bool isOpeningBracket(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check if a character is a closing bracket
bool isClosingBracket(char ch)
{
    return (ch == ')' || ch == ']' || ch == '}');
}

// Check if two brackets match
bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
}

// Main function to check if parentheses are balanced
bool areParenthesesBalanced(const char *expression)
{
    Stack stack;
    initStack(&stack);
    int len = strlen(expression);
    for (int i = 0; i < len; i++)
    {
        char current = expression[i];
        
        // If it's an opening bracket, push it onto the stack
        if (isOpeningBracket(current)) 
        {
            push(&stack, current);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (isClosingBracket(current))
        {
            if (isEmpty(&stack)) {
                // Closing bracket without matching opening bracket
                return false;
            }
            char topBracket = pop(&stack);
            if (!isMatchingPair(topBracket, current))
            {
                // Mismatched brackets
                return false;
            }
        }
    }
    // If stack is empty, all brackets are balanced
    return isEmpty(&stack);
}

// Function to display the result
void checkAndDisplay(const char *expression)
{
    printf("\nExpression: %s\n", expression);
    
    if (areParenthesesBalanced(expression)) {
        printf("Result:Balanced - All parentheses are properly matched!\n");
    } else {
        printf("Result:Unbalanced - Parentheses are not properly matched!\n");
    }
}

int main()
{
    const char *test1 = "a + (b - c) * (d";
    const char *test2 = "m + [a - b * (c + d * {m)]";
    const char *test3 = "a + (b - c)";
    checkAndDisplay(test1);
    checkAndDisplay(test2);
    checkAndDisplay(test3);
    return 0;
}
