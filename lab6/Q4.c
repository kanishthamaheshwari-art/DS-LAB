#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* top = NULL;
int isEmpty() {
    return (top == NULL);
}
void push(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Stack Overflow (Heap Full)!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack\n", value);
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct node* temp = top;
    int popped = temp->data;
    top = temp->next;
    free(temp);
    return popped;
}
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return top->data;
}
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
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