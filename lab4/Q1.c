#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
void MidElement(struct node* head)
{
    struct node* temp=head;
    struct node* temp1=head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp=temp->next;
    }
    if (count % 2 == 0)
    {
        for (int i=0; i<count/2 - 1; i++)
        {
            temp1=temp1->next;
        }
        printf("The middle elements are : %d , %d",temp1->data,temp1->next->data);
    }
    else
    {
        for (int i=0 ; i<count/2 ; i++)
        {
            temp1=temp1->next;
        }
        printf("The middle element is :%d",temp1->data);
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
}
int main()
{
    struct node* head=NULL;
    struct node* temp=head;
    int x;
    printf("Enter the number of elements (except 1) in linked list :");
    scanf("%d",&x);
    for (int i=0 ; i<x ; i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        int y;
        printf("Enter data for node %d : ",i+1);
        scanf("%d",&y);

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        temp->data = y; 
        temp->next = NULL;
    }
    printf("original linked list : ");
    display(head);
    MidElement(head);

    return 0;
}