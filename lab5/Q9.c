#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void split(struct node* head)
{
    struct node* temp=head;
    int count=0;
    do
    {
        count++;
        temp=temp->next;
    } while (temp != head);
    temp=head;
    if (count % 2 == 0)
    {
        for (int i=0 ; i<(count/2)-1 ; i++)
        {
            temp=temp->next;
        }
        struct node* temp1=temp->next;
        for (int i=0 ; i<(count/2)-1 ; i++)
        {
            temp1=temp1->next;
        }
        struct node* head1=temp->next;
        temp1->next=head1;
        temp->next=head;
        temp=head;
        printf("\n First half : \n");
        do 
        {
            printf("%d, ",temp->data);
            temp=temp->next;
        }while(temp != head);
        temp1=head1;
        printf("\n Second half : \n");
        do
        {
            printf("%d, ",temp1->data);
            temp1=temp1->next;
        } while (temp1 != head1); 
    }
    else
    {
        printf("\n the number of nodes are not in even number hence can't be divided in equal half");
    }
}
void display(struct node* head)
{
    struct node* temp=head;
    do
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    } while (temp != head);
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
    n6->next=n1;
    head=n1;
    printf("original linked list : \n");
    display(head);
    split(head);
}