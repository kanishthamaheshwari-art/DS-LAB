#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
bool loop(struct node* head)
{
    bool isLoop=false;
    struct node* temp=head;
    struct node* temp1=head->next;
    while(temp1 != NULL)
    {
        temp1=temp1->next;
        temp=temp->next;
        if (temp1->next == temp)
        {
            isLoop=true;
            break;
        }
    }
}
int main()
{
    struct node* head=NULL;
    struct node *n1,*n2,*n3,*n4;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n1->data=3;
    n2->data=5;
    n3->data=7;
    n4->data=9;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n3;
    head=n1;
    bool isLoop=loop(head);
    if (isLoop)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
