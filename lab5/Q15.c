#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int josephus(struct node* head, int k)
{
    if (head == NULL || k <= 0)
        return -1;
    struct node *temp = head, *prev = NULL;
    int count = 1;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    while (count > 1)
    {
        for (int i = 1; i < k; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head)
            head = temp->next;
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
        count--;
    }
    return temp->data;
}
void display(struct node* head)
{
    struct node* temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}
int main()
{
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    struct node *head = NULL;
    struct node *n1,*n2,*n3,*n4,*n5,*n6;
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    n5=(struct node*)malloc(sizeof(struct node));
    n6=(struct node*)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=3;
    n3->data=5;
    n4->data=7;
    n5->data=9;
    n6->data=10;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n1;
    head=n1;
    printf("Circular Linked List: ");
    display(head);
    int result = josephus(head, k);
    printf("\n Last remaining node: %d\n", result);
    return 0;
}