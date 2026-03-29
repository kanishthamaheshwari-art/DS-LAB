#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of integers in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0],min=arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("\n The maximum element is %d \n",max);
    printf("\nThe minimum element is %d \n",min);
    int sum=0;
    float avg;
    for (int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    avg=sum/n;
    printf("The average of the elements is %f \n",avg);
    int a;
    printf("\nEnter the element to be searched: \n");
    scanf("%d",&a);
    for (int i=0;i<n;i++)
    {
        if (arr[i]==a)
        {
            printf("Element found at index %d \n",i);
            return 0;
        }
        else
        {
            printf("Element not found");
            return 0;
        }
    }
}