#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* reverse(struct node* head)
{
    struct node* current=head;
    struct node* prev=head;
    while(prev->next != head)
    {
        prev=prev->next;
    }
    struct node* next=NULL;
    do
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }while(current != head);
    return prev;
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
    struct node *n1,*n2,*n3,*n4;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=3;
    n3->data=5;
    n4->data=7;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n1;
    head=n1;
    printf("original linked list : \n");
    display(head);
    printf("\n list after reversing : \n");
    head=reverse(head);
    display(head);
}