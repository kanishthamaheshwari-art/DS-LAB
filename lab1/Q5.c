#include <stdio.h>
int main()
{
    int A[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int i = 1, j = 2;   
    int R = 3, C = 3;
    int w = sizeof(int);

    int *BA = &A[0][0];

    int *row_major_addr;
    int *col_major_addr;
    int *actual_addr;

    row_major_addr = BA + (i * C + j);

    col_major_addr = BA + (j * R + i);

    actual_addr = &A[i][j];

    printf("Base Address (A[0][0]) = %p\n\n", (void*)BA);

    printf("Element A[%d][%d] = %d\n\n", i, j, A[i][j]);

    printf("Row-Major Calculated Address = %p\n", (void*)row_major_addr);
    printf("Column-Major Calculated Address = %p\n", (void*)col_major_addr);
    printf("Actual Address in Memory     = %p\n", (void*)actual_addr);

    if (row_major_addr == actual_addr)
        printf("\n Row-Major address matches actual address \n");
    else
        printf("\n Row-Major address does NOT match\n");

    return 0;
}
