#include<stdio.h>
int main()
{
    int a=3;
    float b=4.5;
    char c='z';
    double d=9.87654;

    int k[3]={1,2,3};
    struct student
    {
        int rollno;
        float marks;;
    } s1={101,95.5};

    printf("PRIMITVE DATA TYPES\n");

    printf("Integer value: %d\n",a);
    printf("address of integer:%p \n",(void*)&a);
    printf("size of integer:%zu bytes\n\n",sizeof(a));

    printf("Float value: %.2f\n",b);
    printf("address of float:%p \n",(void*)&b);
    printf("size of float:%zu bytes\n\n",sizeof(b));

    printf("Character value: %c\n",c);
    printf("address of character:%p \n",(void*)&c);
    printf("size of character:%zu bytes\n\n",sizeof(c));

    printf("Double value: %.5lf\n",d);
    printf("address of double:%p \n",(void*)&d);
    printf("size of double:%zu bytes\n\n",sizeof(d));


    printf("NON-PRIMITVE DATA TYPES\n \n");

    printf("Array elements:");
    for (int i=0;i<3;i++)
    {
        printf("%d ",k[i]);
    }
    printf("\n address of array:%p \n",(void*)&k);
    printf("size of array:%zu bytes\n\n",sizeof(k));

    printf("Structure elements:\n");
    printf("Roll number: %d\n",s1.rollno);
    printf("Marks: %.2f\n",s1.marks);
    printf("address of structure:%p \n",(void*)&s1);
    printf("size of structure:%zu bytes\n",sizeof(s1));

}