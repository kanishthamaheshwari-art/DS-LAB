#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* random;
};
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->random = NULL;
    return temp;
}
struct node* cloneList(struct node* head)
{
    if(head == NULL)
        return NULL;
    struct node *curr = head, *temp;
    while(curr != NULL)
    {
        temp = newNode(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }
    curr = head;
    while(curr != NULL)
    {
        if(curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    curr = head;
    struct node* cloneHead = head->next;
    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = temp->next;
        if(temp->next != NULL)
            temp->next = temp->next->next;
        curr = curr->next;
    }
    return cloneHead;
}
void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("Data: %d ", temp->data);
        if(temp->random != NULL)
            printf("Random: %d", temp->random->data);
        else
            printf("Random: NULL");
        printf("\n");
        temp = temp->next;
    }
}
int main()
{
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->random = head->next->next;     
    head->next->random = head;           
    head->next->next->random = head->next; 
    printf("Original List:\n");
    printList(head);
    struct node* cloned = cloneList(head);
    printf("\nCloned List:\n");
    printList(cloned);
    return 0;
}