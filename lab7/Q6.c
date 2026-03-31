#include<stdio.h>
#define max 100
int q[max];
int front = -1,rear=-1;
int stack[max];
int top=-1;

void enqueue(int x)
{
    if (rear + 1 == max)
    {
        printf("queue overflow");
        return;
    }
    if (front == -1)
    {
        front =0;
    }
    q[++rear]=x;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("queue underflow ");
        return-1;
    }
    return q[front++];
}

void push(int x)
{
    if (top + 1 == max)
    {
        printf("stack overflow ");
        return;
    }
    q[++top]=x;
}

int pop()
{
    if (top == -1)
    {
        printf("stack underflow");
        return -1;
    }
    return q[top--];
}

void count()
{
     if (front == -1 || front > rear)
    {
        printf("no element");
        return;
    }
    int count=(rear - front)+ 1;
    printf("the number of elements in the queue is %d\n",count);
}

void sum()
{
     if (front == -1 || front > rear)
    {
        printf("no element");
        return;
    }
    int sum=0;
    for (int i=front ; i<=rear ; i++)
    {
        sum =sum+ q[i];
    }
    printf("the sum of the elements is %d \n",sum);
}

void maxmin()
{
    if (front == -1 || front > rear)
    {
        printf("no element");
        return;
    }
    int MAX=q[0];
    int min=q[0];
    for (int i=front ; i<=rear ; i++)
    {
        if (q[i] > MAX)
        {
            MAX= q[i];
        }
        if (q[i] < min)
        {
            min=q[i];
        }
    }
    printf("the maximum element in the queue is %d \n",MAX);
    printf("the minimum element in the queue is %d \n",min);
}

void reverse()
{
    while(front != rear)
    {
        push(dequeue());
    }

    while( top != -1)
    {
        enqueue(pop());
    }
}

void display()
{
    for (int i=front ; i<=rear ; i++)
    {
        printf("%d ,",q[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    printf("the queue is : \n");
    display();
    count();
    sum();
    maxmin();
    printf("the reversed queue is : \n");
    reverse();
    display();
}