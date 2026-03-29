#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* insertAtBeginning(struct node* head, int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    return newnode;
};
struct node* insertAtEnd(struct node* head ,int y)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=y;
    newnode->next=NULL;
    if(head==NULL)
    return newnode;
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
struct node* insertAtPosition(struct node* head,int pos,int val)
{
    if(pos==1)
    {
        return insertAtBeginning(head,val);
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    struct node* temp=head;
    for (int i=1 ; i < pos-1 && temp != NULL; i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("position out of range");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* head = NULL;
    head=insertAtBeginning(head,4);
    printf("After inserting 4 at beginning \n");
    display(head);
    head=insertAtEnd(head,10);
    printf("After inserting 10 at end \n");
    display(head);
    head=insertAtPosition(head,3,4);
    printf("After inserting 4 at position 3 \n");
    display(head);
    return 0;
}
