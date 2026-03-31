#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* movelastnode(struct node* head)
{
    struct node* temp1=head;
    struct node* temp2=head;
    while(temp1->next != NULL)
    {
        temp1=temp1->next;
    }
    while(temp2->next->next != NULL)
    {
        temp2=temp2->next;
    }
    temp1->next=head;
    temp2->next=NULL;
    head=temp1;
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* head=NULL;
    struct node *n1, *n2, *n3, *n4, *n5,*n6;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n6=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=2;
    n3->data=3;
    n4->data=4;
    n5->data=5;
    n6->data=6;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    head=n1;
    printf("original linked list: \n");
    display(head);
    printf(" \n linked list after moving last node to head : \n");
    head=movelastnode(head);
    display(head);
}