#include<stdio.h>
int main()
{
    int a[3][3];
    printf("Enter the values of matrix");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix A is :");
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    printf("the address of array is:");
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%p ",(void*)&a[i][j]);
        }
        printf("\n");
    }
    printf("the address of a[0][1] is %p\n",(void*)&a[0][1]);
    printf("the address of a[0][0] is %p\n",(void*)&a[0][0]);
    printf("address of a[0][1]=address of a[0][0]+sizeof(a)*1\n");
    printf("Hence it is row-major");
}