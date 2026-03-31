#include<stdio.h>
#include<stdbool.h>
#define max 100
char q[max];
int front=-1 , rear=-1;

void enqueue(char x)
{
    if (rear + 1 == max)
    {
        printf("queue overflow ");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    q[++rear]=x;
    printf("inserted %c \n",x);
}

void dequeue()
{
    int temp1=front;
    if (rear == -1 || front > rear)
    {
        printf("queue underflow");
        return;
    }
    printf("deleted %c",q[front]);
    front++;
}

void palindrome()
{
    bool isPalindrome=true;
    int temp1=front;
    int temp2=rear;
    for (int i=0 ; i<=(front + rear)/2 ; i++)
    {
        if (q[temp1] == q[temp2])
        {
            temp1++;
            temp2--;
        }
        else
        {
            isPalindrome=false;
            break;
        }
    }
    if(isPalindrome)
    {
        printf("\n it is palindrome");
    }
    else
    {
        printf("\n it is not palindrome");
    }
}

int main()
{
    enqueue('m');
    enqueue('a');
    enqueue('d');
    enqueue('a');
    enqueue('m');
    palindrome();
}