#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';  // return empty instead of -1
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char* exp) {
    char postfix[SIZE];
    int k = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if (top != -1 && stack[top] == '(')
                pop(); // remove '('
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char exp[SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}

