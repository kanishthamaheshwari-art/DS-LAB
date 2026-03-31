#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void duplicates(struct node* head)
{
    struct node* temp=head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            struct node* temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
        }
        else
        {
            temp=temp->next;
        }
    }
}
void display(struct node* head)
{
    struct node* temp=head;
    while (temp != NULL)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
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
    n1->data=2;
    n2->data=2;
    n3->data=2;
    n4->data=5;
    n5->data=5;
    n6->data=7;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    head=n1;
    printf("original linked list :");
    display(head);
    printf("\nlinked list after removing duplicates :");
    duplicates(head);
    display(head);
}