#include<stdio.h>
#define SIZE 10

struct stack {
    int stack[SIZE];
    int top;
} s;

void push();
void pop();
void display();

int main() {
    int choice, option = 1;
    s.top = -1;

    printf("STACK OPERATIONS\n");
    while(option) {
        printf("\n----------------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n\n");
        }
        printf("\nDo you want to continue (press 0 or 1)?: ");
        scanf("%d", &option);
    }
}

void push() {
    int num;
    if (s.top == SIZE - 1) {
        printf("\nSTACK OVERFLOW");
        printf("\nStack is already full!");
        return;
    }
    else {
        printf("\nEnter the element to be pushed: ");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stack[s.top] = num;
    }
}

void pop() {
    int num;
    if (s.top == -1) {
        printf("\nSTACK UNDERFLOW");
        printf("\nStack is already empty!");
        return;
    }
    else {
        num = s.stack[s.top];
        printf("\nPopped element: %d", s.stack[s.top]);
        s.top = s.top - 1;
    }
}

void display() {
    if (s.top == -1) {
        printf("The stack is empty!");
        return;
    }
    printf("The stack is:\t");
    for (int i = s.top; i != -1; i--)
        printf("%d\t", s.stack[i]);
}

void push_param(int item, int *top, int arr[]) {
    if (*top == SIZE - 1) {
        printf("STACK OVERFLOW\n");
        return;
    }
    arr[++(*top)] = item;
}

void push_param_c(int item, int *top, char arr[]) {
    if (*top == SIZE - 1) {
        printf("STACK OVERFLOW\n");
        return;
    }
    arr[++(*top)] = item;
}

int pop_param(int *top, int arr[]) {
    int deleted_item;
    if (*top == -1) {
        printf("STACK UNDERFLOW\n");
        return 0;
    }
    deleted_item = arr[(*top)--];
    return deleted_item;
}

char pop_param_c(int *top, char arr[]) {
    char deleted_item;
    if (*top == -1) {
        printf("STACK UNDERFLOW\n");
        return 0;
    }
    deleted_item = arr[(*top)--];
    return deleted_item;
}

void display_param(int top, int arr[]) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("\nThe Stack is:\t");
    for (int i = top; i != -1; i--)
        printf("%d\t", arr[i]);
}
