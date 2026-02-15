#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

// Stack for characters
typedef struct 
{
    char data[MAX_SIZE];
    int top;
} CharStack;

// Stack for integers
typedef struct
{
    int data[MAX_SIZE];
    int top;
} IntStack;

void initCharStack(CharStack *s) 
{
    s->top = -1;
}

bool isCharStackEmpty(CharStack *s) 
{
    return s->top == -1;
}

void pushChar(CharStack *s, char ch) 
{
    if (s->top < MAX_SIZE - 1)
        s->data[++s->top] = ch;
}

char popChar(CharStack *s) 
{
    if (!isCharStackEmpty(s))
        return s->data[s->top--];
    return '\0';
}

char peekChar(CharStack *s) 
{
    if (!isCharStackEmpty(s))
        return s->data[s->top];
    return '\0';
}

void initIntStack(IntStack *s) 
{
    s->top = -1;
}

bool isIntStackEmpty(IntStack *s) 
{
    return s->top == -1;
}

void pushInt(IntStack *s, int val) 
{
    if (s->top < MAX_SIZE - 1)
        s->data[++s->top] = val;
}

int popInt(IntStack *s) 
{
    if (!isIntStackEmpty(s))
        return s->data[s->top--];
    return 0;
}

bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || 
            ch == '/' || ch == '^' || ch == '%');
}

int getPrecedence(char op) 
{
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^': return 3;
        default:  return 0;
    }
}

bool isRightAssociative(char op) 
{
    return (op == '^');
}

void infixToPostfix(const char *infix, char *postfix) 
{
    CharStack stack;
    initCharStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) 
    {
        char ch = infix[i];
        if (isspace(ch))
            continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            pushChar(&stack, ch);
        }
        else if (ch == ')') {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(')
                postfix[j++] = popChar(&stack);
            popChar(&stack); 
        }
        else if (isOperator(ch)) {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(' &&
                  (getPrecedence(peekChar(&stack)) > getPrecedence(ch) ||
                  (getPrecedence(peekChar(&stack)) == getPrecedence(ch) &&
                   !isRightAssociative(ch)))) {
                postfix[j++] = popChar(&stack);
            }
            pushChar(&stack, ch);
        }
    }

    while (!isCharStackEmpty(&stack))
        postfix[j++] = popChar(&stack);

    postfix[j] = '\0';
}

int performOperation(int a, int b, char op) 
{
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        case '%': return a % b;
        case '^': return (int)pow(a, b);
        default:  return 0;
    }
}

int evaluatePostfix(const char *postfix) 
{
    IntStack stack;
    initIntStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) 
    {
        char ch = postfix[i];

        if (isdigit(ch)) {
            pushInt(&stack, ch - '0');
        }
        else if (isOperator(ch)) {
            int b = popInt(&stack);
            int a = popInt(&stack);
            pushInt(&stack, performOperation(a, b, ch));
        }
    }
    return popInt(&stack);
}

int main() {
    const char *testExpressions[] = 
    {
        "3+4*2",
        "(3+4)*2",
        "2^3^2",
        "5+((1+2)*4)-3",
        "a+b*c-d"
    };

    int numTests = 5;

    for (int i = 0; i < numTests; i++) 
    {
        char postfix[MAX_SIZE];

        printf("\nInfix   : %s\n", testExpressions[i]);
        infixToPostfix(testExpressions[i], postfix);
        printf("Postfix : %s\n", postfix);

        bool canEvaluate = true;
        for (int j = 0; testExpressions[i][j] != '\0'; j++) {
            if (isalpha(testExpressions[i][j])) {
                canEvaluate = false;
                break;
            }
        }
        if (canEvaluate)
            printf("Result  : %d\n", evaluatePostfix(postfix));
        else
            printf("Result  : Cannot evaluate (variables present)\n");
    }
    return 0;
}
