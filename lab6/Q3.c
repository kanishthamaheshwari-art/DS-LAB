#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed into stack\n", value);
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack[top];
}
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    display();
    if (isEmpty())
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
    return 0;
}