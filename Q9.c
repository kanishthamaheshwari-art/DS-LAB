#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* findIntersection(struct node* head1, struct node* head2)
{
    if(head1 == NULL || head2 == NULL)
        return NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    while(ptr1 != ptr2)
    {
        ptr1 = (ptr1 == NULL) ? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }
    return ptr1;
}
void display(struct node* head1)
{
    struct node* temp = head1;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    head1->data = 1;
    head1->next = (struct node*)malloc(sizeof(struct node));
    head1->next->data = 2;
    head1->next->next = (struct node*)malloc(sizeof(struct node));
    head1->next->next->data = 3;
    head1->next->next->next = NULL;
    display(head1);
    head2->data = 4;
    head2->next = (struct node*)malloc(sizeof(struct node));
    head2->next->data = 5;
    head2->next->next = head1->next; 
    display(head2);
    struct node* intersection = findIntersection(head1, head2);
    if(intersection != NULL)
        printf("Intersection at node with data: %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}
