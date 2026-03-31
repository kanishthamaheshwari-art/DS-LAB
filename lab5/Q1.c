#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void sumfound(struct node* head,int sum)
{
    struct node* temp=head;
    struct node* temp1=head;
    while(temp != NULL)
    {
        temp1=temp;
        while(temp1 != NULL)
        {
            if (sum - temp->data == temp1->data)
            {
                printf("(%d , %d)",temp->data,temp1->data);
            }
                temp1=temp1->next;
        }
            temp=temp->next;
    }
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d , ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* head=NULL;
    struct node *n1,*n2,*n3,*n4,*n5;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=2;
    n3->data=3;
    n4->data=4;
    n5->data=5;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    head=n1;
    int sum;
    printf("Enter the sum you want : ");
    scanf("%d",&sum);
    printf("original linked list : \n");
    display(head);
    printf("the pairs with sum %d are : ",sum);
    sumfound(head,sum);
    
}