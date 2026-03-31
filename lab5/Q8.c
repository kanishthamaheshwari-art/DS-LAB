#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
    struct node* random;
};
struct node* insert(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    temp->random = NULL;
    if (head == NULL)
        return temp;
    struct node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    return head;
}
struct node* cloneList(struct node* head) {
    if (head == NULL) return NULL;
    struct node* curr = head;
    while (curr != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = curr->data;
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
        curr = temp->next;
    }
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        else
            curr->next->random = NULL;
        curr = curr->next->next;
    }
    curr = head;
    struct node* cloneHead = head->next;
    struct node* clone;
    while (curr != NULL) {
        clone = curr->next;
        curr->next = clone->next;
        if (clone->next != NULL)
            clone->next = clone->next->next;
        curr = curr->next;
    }
    return cloneHead;
}
void display(struct node* head) {
    while (head != NULL) {
        printf("Data: %d ", head->data);
        if (head->random)
            printf("Random: %d\n", head->random->data);
        else
            printf("Random: NULL\n");
        head = head->next;
    }
}
int main() {
    struct node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head->random = head->next->next;     
    head->next->random = head;         
    head->next->next->random = head->next; 
    printf("Original List:\n");
    display(head);
    struct node* clone = cloneList(head);
    printf("\nCloned List:\n");
    display(clone);
    return 0;
}