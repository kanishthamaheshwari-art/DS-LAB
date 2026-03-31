#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
 struct node* reverse(struct node* head, int k)
{
    struct node* temp=head;
    struct node* temp1=NULL;
    struct node* temp2=NULL;
    int count=0;
    while(temp != NULL && count < k)
    {
        temp2=temp->next;
        temp->next=temp1;
        temp1=temp;
        temp=temp2;
        count++;
    }
    if (temp2 != NULL)
    {
        struct node* rest_head=reverse(temp2, k);
        head->next=rest_head;
    }
    else
    {
        head->next=NULL;
    }
    return temp1;
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
    n1->data=1;
    n2->data=2;
    n3->data=3;
    n4->data=4;
    n5->data=5;
    n6->data=6;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    head=n1;
    int k;
    printf("Enter the value of k: ");
    scanf("%d",&k);
    printf("Original linked list: ");
    display(head);
    head=reverse(head,k);
    printf("after reversing the list in groups of k : \n");
    display(head);
    return 0;
}
