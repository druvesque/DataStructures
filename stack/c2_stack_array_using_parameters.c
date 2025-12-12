#include<stdio.h>
#define SIZE 10

struct stack {
    char stack[SIZE];
    int top;
} s;

void push(char item, int *top) {
    if (*top == SIZE - 1) {
        printf("STACK OVERFLOW\n");
        return;
    }
    s.stack[++(*top)] = item;
}

void pop(int *top) {
    int deleted_item;
    if (*top == -1) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    deleted_item = s.stack[(*top)--];
    printf("\nPopped element: %c", deleted_item); 
}

void display(int *top) {
    if (*top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("\nThe Stack is:\t");
    for (int i = (*top); i != -1; i--) 
        printf("%c\t", s.stack[i]);
}

int main() {
    s.top = -1;
    push('T', &s.top);
    push('I', &s.top);
    push('M', &s.top);
    push('E', &s.top);
    display(&s.top);
    pop(&s.top);
    display(&s.top);
    return 0;
}
