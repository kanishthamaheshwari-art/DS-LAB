#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* bottom;
};
struct node* merge(struct node* a, struct node* b)
{
    if(a == NULL) 
    return b;
    if(b == NULL) 
    return a;
    struct node* result;
    if(a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}
struct node* flatten(struct node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    head->next = flatten(head->next);
    head = merge(head, head->next);
    return head;
}
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->bottom = NULL;
    return temp;
}
void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->bottom;
    }
}
int main()
{
    struct node* head = newNode(5);
    head->bottom = newNode(7);
    head->bottom->bottom = newNode(8);
    head->bottom->bottom->bottom = newNode(30);
    head->next = newNode(10);
    head->next->bottom = newNode(20);
    head->next->next = newNode(19);
    head->next->next->bottom = newNode(22);
    head->next->next->bottom->bottom = newNode(50);
    head->next->next->next = newNode(28);
    head->next->next->next->bottom = newNode(35);
    head->next->next->next->bottom->bottom = newNode(40);
    head->next->next->next->bottom->bottom->bottom = newNode(45);
    head = flatten(head);
    printList(head);
    return 0;
}