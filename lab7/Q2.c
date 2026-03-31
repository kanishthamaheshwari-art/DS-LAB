#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
void enqueue(int x)
{
    struct node* q= (struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->next=NULL;
    if (rear == NULL)
    {
        front=rear=q;
    }
    else
    {
        rear->next=q;
        rear=q;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("queue underflow");
    }
    struct node* temp=front;
    printf("\n the deleted element is %d\n ",front->data);
    front=front->next;
    if (front == NULL)
    {
        printf("queue is empty");
    }
    free(temp);
}

void display()
{
    struct node* temp=front;
    while(temp != NULL)
    {
        printf("%d, ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}