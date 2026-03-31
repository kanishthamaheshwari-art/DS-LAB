#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* mergeTwo(struct node* a, struct node* b)
{
    if(a == NULL) 
    return b;
    if(b == NULL) 
    return a;
    if(a->data <= b->data)
    {
        a->next = mergeTwo(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeTwo(a, b->next);
        return b;
    }
}
struct node* merge(struct node* lists[])
{
    struct node* result = NULL;

    for(int i = 0; i < 2; i++)
        result = mergeTwo(result, lists[i]);

    return result;
}
struct node* createlist(int n)
{
    struct node* head=NULL,*temp=NULL,*newnode=NULL;
    for (int i=0 ; i<n ; i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if (head == NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("NULL \n");
}
int main()
{
    struct node* lists[2];
    printf("Enter the elements of each linked list :\n");
    for (int i=0 ; i<2 ; i++)
    {
        int n;
        printf("Enter number of nodes for list %d ",i+1);
        scanf("%d",&n);
        printf("enter %d sorted elements : ",n);
        lists[i]=createlist(n);
    }
    printf("Merged and sorted linked list is : \n");
    struct node* mergedList = merge(lists);
    display(mergedList);
}