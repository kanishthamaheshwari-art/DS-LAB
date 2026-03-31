#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}s1,p1;
struct node* sortandmerge(s1* head1 , p1* head2)
{
    struct node* temp1=head1;
    struct node* temp2=head2;
    while(temp1->next != NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;
    temp1=head1;
    int count=0;
    while(temp1->next != NULL)
    {
        count++;
        temp1=temp1->next;
    }
    temp1=head1;
    struct node* fast=temp1->next->next;
    struct node* slow= temp1->next;
    struct node* slower=temp1;
    for (int i=0 ; i<count-2 ; i++)
    {
        for (int j=i+1 ; j<count-1 ; j++)
        {
            if ( slow->data > fast->data)
            {
                struct node* temp=fast->next;
                slow->next=temp;
                slower->next=fast;
                fast->next=slow;
                slower=fast;
                fast=slow->next;
            }
            else
            {
               continue;
            }
             slower=slower->next;
                slow=slow->next;
                fast=fast->next;
        }
        slower=head1;
        slow=head1->next;
        fast=head1->next->next;
    }
    return head1;
}
void display(struct node* head1)
{
    struct node* temp=head1;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
void display1(struct node* head2)
{
    struct node* temp=head2;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    s1* head1=NULL;
    p1* head2=NULL;
    s1 *n1,*n2,*n3;
    p1 *m1,*m2,*m3,*m4;
    n1=(s1*)malloc(sizeof(s1));
    n2=(s1*)malloc(sizeof(s1));
    n3=(s1*)malloc(sizeof(s1));
    m1=(p1*)malloc(sizeof(p1));
    m2=(p1*)malloc(sizeof(p1));
    m3=(p1*)malloc(sizeof(p1));
    m4=(p1*)malloc(sizeof(p1));
    m1->data=2;
    m2->data=4;
    m3->data=5;
    m4->data=7;
    m1->next=m2;
    m2->next=m3;
    m3->next=m4;
    m4->next=NULL;
    n1->data=1;
    n2->data=3;
    n3->data=8;
    n1->next=n2;
    n2->next=n3;
    n3->next=NULL;
    head1=n1;
    head2=m1;
    printf("first linked list is : \n");
    display(head1);
    printf("second linked list is : \n");
    display1(head2);
    struct node* head=sortandmerge(head1,head2);
    printf("merged and sorted linked list is : \n");
    display(head);
    return 0;
}