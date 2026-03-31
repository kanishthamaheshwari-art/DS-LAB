#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void checkSorted(struct node* head)
{
    struct node* temp=head;
    int flag=1;
    do
    {
        if (temp->data > temp->next->data)
        {
            if (temp->next != head)
            {
                flag=0;
                break;
            }
            temp=temp->next;
        }
    } while (temp != head);
    if(flag)
    {
        printf("\n the circular list is SORTED \n");
    }
    else
    {
        printf("\n the circular list is UNSORTED ");
    }
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
    checkSorted(head);
}
