#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *arr;
    int top;
    unsigned capacity;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->arr[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) return '\0';
    return stack->arr[stack->top--];
}

char* isBalanced(char* str) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    
    for (int i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(stack)) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
            
            char top = pop(stack);
            if ((top == '(' && str[i] != ')') ||
                (top == '{' && str[i] != '}') ||
                (top == '[' && str[i] != ']')) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
        }
    }
    
    if (isEmpty(stack)) {
        free(stack->arr);
        free(stack);
        return "YES";
    } else {
        free(stack->arr);
        free(stack);
        return "NO";
    }
}

int main() {
    char input[100];
    printf("Masukkan urutan tanda kurung: ");
    scanf("%s", input);

    printf("%s\n", isBalanced(input));
    
    return 0;
}
