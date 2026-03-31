#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
 struct node* palindrome(struct node* head)
{
    struct node* current=head;
    struct node* newHead=head;
    while(newHead->next != NULL)
    {
        newHead=newHead->next;
    }
    while (current != NULL)
    {
        current->next=current->prev;
        current=current->next;
    }
    struct node* temp=head;
    struct node* temp1=newHead;
    while(temp != NULL && temp1 != NULL)
    {
        if(temp->data != temp1->data)
        {
            printf("The linked list is not a palindrome.\n");
        }
        else
        {
            printf("The linked list is a palindrome.\n");
        }
        temp=temp->next;
        temp1=temp1->next;
    }
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
    struct node *n1, *n2, *n3, *n4, *n5,*n6;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n6=(struct node*)malloc(sizeof(struct node));
    n1->data=9;
    n2->data=8;
    n3->data=7;
    n4->data=7;
    n5->data=8;
    n6->data=9;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    n6->prev=n5;
    n1->prev=NULL;
    head=n1;
    printf("Original linked list: ");
    display(head);
    palindrome(head);
    return 0;
}