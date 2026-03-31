#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* reverselist(struct node* head, int k)
{
    struct node* temp=head;
    struct node* temp1=head;
    int count=0;
    while(temp != NULL && count<k-1)
    {
        temp=temp->next;
        count++;
    }
    struct node* temp2=temp->next;
    while(temp1->next != NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=head;
    temp->next=NULL;
    head=temp2;
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
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
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    n5->data=50;
    n6->data=60;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    head=n1;
    int k;
    printf("Enter the value of k");
    scanf("%d",&k);
    printf("original linked list : \n");
    display(head);
    printf("list after reversing it by %d \n",k);
    head=reverselist(head,k);
    display(head);
}