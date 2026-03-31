#include<stdio.h>
#define max 5
int q[max];
int front=-1,rear=-1;

void enqueue(int x)
{
    if( rear == max -1 || front == rear +1)
    {
        printf("queue overflow ");
        return;
    }
    if (front == -1)
    {
        front = rear =0;
    }
    else if (rear == max -1)
    {
       rear = 0;
    }
    else 
    {
        rear++;
    }
    q[rear]=x;
    printf("inserted %d \n",x);
}

void dequeue()
{
    if (front == -1)
    {
        printf("queue underflow ");
        return;
    }
    printf("deleted %d \n",q[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == max-1)
    {
        front =0;
    }
    else 
    {
        front++;
    }
}

void display()
{
    if (rear > front)
    {
        for (int i=front ; i<=rear ; i++)
        {
            printf("%d, ",q[i]);
        }
        printf("\n");
    }
    else
    {
        int temp=front;
        while(temp != rear)
        {
            printf("%d, ",q[temp]);
            temp++;
            temp=temp % max;
        }
        printf(" %d\n ",q[rear]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    display();
}
