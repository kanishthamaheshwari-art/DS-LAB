#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* swapNodes(struct node* head, int k1, int k2)
{
    if(k1 == k2)
        return head;
    struct node *prev1=NULL, *prev2=NULL;
    struct node *curr1=head, *curr2=head;
    for(int i=1;i<k1;i++)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    for(int i=1;i<k2;i++)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if(curr1==NULL || curr2==NULL)
        return head;
    if(prev1 != NULL)
        prev1->next = curr2;
    else
        head = curr2;
    if(prev2 != NULL)
        prev2->next = curr1;
    else
        head = curr1;
    struct node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
    return head;
}
void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node* head = NULL;
    struct node* temp;
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<5;i++)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if(head==NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original List:\n");
    printList(head);
    head = swapNodes(head,2,4);
    printf("After Swapping:\n");
    printList(head);
    return 0;
}