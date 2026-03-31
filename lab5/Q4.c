#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
int maxSublistSum(struct Node* head) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        currentSum += temp->data;
        if (currentSum > maxSum)
            maxSum = currentSum;
        if (currentSum < 0)
            currentSum = 0;
        temp = temp->next;
    }
    return maxSum;
}
int main() {
    struct Node* head = NULL;
    append(&head, -2);
    append(&head, 1);
    append(&head, -3);
    append(&head, 4);
    append(&head, -1);
    append(&head, 2);
    append(&head, 1);
    append(&head, -5);
    append(&head, 4);
    printf("Maximum Sublist Sum = %d", maxSublistSum(head));
    return 0;
}