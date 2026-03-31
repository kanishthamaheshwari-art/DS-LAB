#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void countNodes(struct node* head)
{
    struct node* temp=head;
    int count=1;
    while(temp->next != head)
    {
        count++;
        temp=temp->next;
    }
    if (count == 1)
    {
        printf("\n No loop detected, only one node present");
    }
    else 
    {
        printf("\n Loop detected . number of nodes = %d ",count);
    }
}
void display(struct node* head)
{
    struct node* temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}
int main()
{
    struct node* head=NULL;
    struct node *n1,*n2,*n3,*n4,*n5,*n6;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n6=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=3;
    n3->data=5;
    n4->data=7;
    n5->data=9;
    n6->data=10;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n1;
    head=n1;
    printf("original linked list ; \n");
    display(head);
    countNodes(head);
}