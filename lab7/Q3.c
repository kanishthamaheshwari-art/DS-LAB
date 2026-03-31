#include<stdio.h>
#define max 100
int stack1[max],stack2[max];
int top1=-1,top2=-1;
void push1(int x)
{
    if (top1 + 1 == max)
    {
        printf("stack 1 overflow");
        return;
    }
    stack1[++top1]=x;
}

void push2(int x)
{
    if (top2 + 1 == max)
    {
        printf("stack 2 overflow");
        return;
    }
    stack2[++top2]=x;
}

int pop1()
{
    if (top1 == -1)
    {
        printf("stack 1 underflow");
        return -1;
    }
    return stack1[top1--];
}

int pop2()
{
    if (top2 == -1)
    {
        printf("stack 2 underflow");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int x)
{
    push1(x);
     printf("inserted %d \n",x);
}

void dequeue()
{
    if (top2 == -1)
    {
        while(top1 != -1)
        {
            push2(pop1());
        }
    }
    printf("deleted %d \n",pop2());
}

void display()
{
    for (int i=top2 ; i>=0 ; i--)
    {
        printf("%d , ",stack2[i]);
    }
    printf("\n");
    for (int i=0 ; i<=top1 ; i++)
    {
        printf("%d, ",stack1[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    display();
}