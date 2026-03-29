#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* deleteData(struct node* head,int x)
{
    struct node* temp=head;
    struct node* p1=head;
    int i=0;
    while (temp->next != NULL)
    {
        temp=temp->next;
        i++;
    }
    if (x > i+1)
    {
        printf("position out of range");
    }
    else
    {
        for (int j=1;j<x-1;j++)
        {
            p1=p1->next;
        }
    }
    struct node* delData=p1->next;
    p1->next=delData->next;
    free(delData);
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while (temp != NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* head= NULL;
    struct node *n1,*n2,*n3;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n1->next=n2;
    n2->next=n3;
    n3->next=NULL;
    head=n1;
    printf("original link list : \n");
    display(head);
    int x;
    printf("Enter the position");
    scanf("%d",&x);
     head=deleteData(head,x);
    printf("After deleting the data at position %d : \n",x);
    display(head);
}