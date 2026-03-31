#include<stdio.h>
#include<stdlib.h>
#define max 100
int q[max];
int front=-1,rear=-1;

void enqueue(int x)
{
    if (rear + 1 == max)
    {
        printf("queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    q[++rear]=x;
}

int dequeue()
{
    if ( front == -1 || front > rear)
    {
        printf("queue underflow \n ");
        return -1;
    }
    return q[front++];
}

int peek()
{
    return q[front];
}

void display()
{
   for (int i=front ; i<=rear ; i++)
   {
    printf("%d, ",q[i]);
   }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("\n the top element is %d \n",peek());
    printf("the element removed is %d \n",dequeue());
    printf("now the queue is : \n");
    display();
}