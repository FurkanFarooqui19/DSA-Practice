#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return 1;
    if (opening == '{' && closing == '}')
        return 1;
    if (opening == '[' && closing == ']')
        return 1;
    return 0;
}

int isWellFormed(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char current = exp[i];
        
        // Push opening parentheses to stack
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        }
        // For closing parentheses
        else if (current == ')' || current == '}' || current == ']') {
            // If stack is empty or mismatch occurs
            if (top == -1 || !isMatchingPair(pop(), current)) {
                return 0;  // Not well-formed
            }
        }
    }
    
    // Stack should be empty at the end if well-formed
    return (top == -1);
}

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    scanf("%s", expression);
    
    if (isWellFormed(expression)) {
        printf("The expression is well-formed.\n");
    } else {
        printf("The expression is not well-formed.\n");
    }
    
    return 0;
}
