#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* insert(struct node* head,struct node* x)
{
    struct node* temp=head;
    if (x->data < head->data)
    {
        while (temp->next != head)
            temp = temp->next;
        temp->next = x;
        x->next = head;
        head = x; 
        return head;
    }
    temp=head;
    while (x->data >= temp->next->data)
    {
        temp=temp->next;
    }
    x->next=temp->next;
    temp->next=x;
    return head;
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
    struct node* x;
    x=(struct node*)malloc(sizeof(struct node));
    struct node *n1,*n2,*n3,*n4,*n5,*n6;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n6=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=3;
    n3->data=6;
    n4->data=9;
    n5->data=12;
    n6->data=15;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n1;
    head=n1;
    int k;
    printf("Enter the data you want to insert : \n");
    scanf("%d",&k);
    x->data=k;
    printf("original list \n");
    display(head);
    printf("\n list after inserting the data : \n");
    head=insert(head,x);
    display(head);
}