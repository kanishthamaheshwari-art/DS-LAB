#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
void deleteduplicatenodes(struct node* head)
{
    struct node* temp=head;
    struct node* temp1=head->next;
    while (temp != NULL)
    {
        temp1=temp->next;
        while(temp1 != NULL)
        {
            if (temp->data == temp1->data)
            {
                if(temp1->prev != NULL)
                    temp1->prev->next = temp1->next;

                if(temp->next != NULL)
                    temp->next->prev = temp->prev;
                    if(temp->prev != NULL)
                    temp->prev->next = temp->next;

                if(temp->next != NULL)
                    temp->next->prev = temp->prev;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
    free(temp);
    free(temp1);
}
void display(struct node* head)
{
    struct node* temp=head;
    while(temp != NULL)
    {
        printf("%d, ",temp->data);
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
    n1->data=5;
    n2->data=2;
    n3->data=3;
    n4->data=5;
    n5->data=2;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    n1->prev=NULL;
    head=n1;
    printf("Original linked list : \n");
    display(head);
    printf("list after removing the duplicates : \n");
    deleteduplicatenodes(head);
    display(head);
}