#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* revData(struct node* head)
{
    struct node* temp=head;
    struct node* p=NULL;
    struct node* r=NULL;
    while (temp != NULL)
    {
        p=temp->next;
        temp->next=r;
        r=temp;
        temp=p;
    }
    return r;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* head=NULL;
    struct node* n1,*n2,*n3;
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
    printf("Original link list :");
    display(head);
    head=revData(head);
    printf("After reversing link list :");
    display(head);
    return 0;
}