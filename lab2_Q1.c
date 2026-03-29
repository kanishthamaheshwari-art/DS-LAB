#include <stdio.h>

void displayArray(int arr[], int size);

void insertAtEnd(int arr[], int *size, int value);
void insertAtBeginning(int arr[], int *size, int value);
void insertAtPosition(int arr[], int *size, int value, int pos);

void deleteFromEnd(int arr[], int *size);
void deleteFromBeginning(int arr[], int *size);
void deleteFromPosition(int arr[], int *size, int pos);

void reverseWithTemp(int arr[], int size);
void reverseInPlace(int arr[], int size);

int sumWithoutRecursion(int arr[], int size);
int sumWithRecursion(int arr[], int size);

int searchElement(int arr[], int size, int key);

void separateOddEven(int arr[], int size);
void separatePosNeg(int arr[], int size);

int main()
{
    int SubArray1[10], SubArray2[10], MainArray[20];
    int size;
    int choice, value, pos, key;
    printf("Enter number of elements in main array");
    scanf("%d",&size);
    printf("Enter elements for MainArray :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &MainArray[i]);
    }

    do {
        printf("\n------ ARRAY OPERATIONS MENU ------\n");
        printf("1. Insert at End (MainArray)\n");
        printf("2. Insert at Beginning (MainArray)\n");
        printf("3. Insert at Position (MainArray)\n");
        printf("4. Delete from End (MainArray)\n");
        printf("5. Delete from Beginning (MainArray)\n");
        printf("6. Delete from Position (MainArray)\n");
        printf("7. Reverse using Temporary Array\n");
        printf("8. Reverse In-Place\n");
        printf("9. Sum of elements (Without Recursion)\n");
        printf("10. Sum of elements (Using Recursion)\n");
        printf("11. Search an element\n");
        printf("12. Separate Odd & Even\n");
        printf("13. Separate Positive & Negative\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(MainArray, &size, value);
                displayArray(MainArray, size);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(MainArray, &size, value);
                displayArray(MainArray, size);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(MainArray, &size, value, pos);
                displayArray(MainArray, size);
                break;

            case 4:
                deleteFromEnd(MainArray, &size);
                displayArray(MainArray, size);
                break;

            case 5:
                deleteFromBeginning(MainArray, &size);
                displayArray(MainArray, size);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(MainArray, &size, pos);
                displayArray(MainArray, size);
                break;

            case 7:
                reverseWithTemp(MainArray, size);
                displayArray(MainArray, size);
                break;

            case 8:
                reverseInPlace(MainArray, size);
                displayArray(MainArray, size);
                break;

            case 9:
                printf("Sum = %d\n", sumWithoutRecursion(MainArray, size));
                break;

            case 10:
                printf("Sum = %d\n", sumWithRecursion(MainArray, size));
                break;

            case 11:
                printf("Enter value to search: ");
                scanf("%d", &key);
                pos = searchElement(MainArray, size, key);
                if(pos != -1)
                    printf("Found at position %d\n", pos);
                else
                    printf("Not found\n");
                break;

            case 12:
                separateOddEven(MainArray, size);
                break;

            case 13:
                separatePosNeg(MainArray, size);
                break;
        }

    } while(choice != 0);

    return 0;
}

void displayArray(int arr[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertAtEnd(int arr[], int *size, int value)
{
    if(*size < 20)
        arr[(*size)++] = value;
}

void insertAtBeginning(int arr[], int *size, int value)
{
    if(*size < 20)
    {
        for(int i = *size; i > 0; i--)
            arr[i] = arr[i-1];
        arr[0] = value;
        (*size)++;
    }
}

void insertAtPosition(int arr[], int *size, int value, int pos)
{
    if(*size < 20 && pos >= 0 && pos <= *size)
    {
        for(int i = *size; i > pos; i--)
            arr[i] = arr[i-1];
        arr[pos] = value;
        (*size)++;
    }
}

void deleteFromEnd(int arr[], int *size)
{
    if(*size > 0)
        (*size)--;
}

void deleteFromBeginning(int arr[], int *size)
{
    if(*size > 0)
    {
        for(int i = 0; i < *size-1; i++)
            arr[i] = arr[i+1];
        (*size)--;
    }
}

void deleteFromPosition(int arr[], int *size, int pos)
{
    if(pos >= 0 && pos < *size)
    {
        for(int i = pos; i < *size-1; i++)
            arr[i] = arr[i+1];
        (*size)--;
    }
}

void reverseWithTemp(int arr[], int size)
{
    int temp[20];
    for(int i = 0; i < size; i++)
        temp[i] = arr[size - i - 1];
    for(int i = 0; i < size; i++)
        arr[i] = temp[i];
}

void reverseInPlace(int arr[], int size)
{
    int temp;
    for(int i = 0; i < size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

int sumWithoutRecursion(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int sumWithRecursion(int arr[], int size)
{
    if(size == 0)
        return 0;
    return arr[size-1] + sumWithRecursion(arr, size-1);
}

int searchElement(int arr[], int size, int key)
{
    for(int i = 0; i < size; i++)
        if(arr[i] == key)
            return i;
    return -1;
}

void separateOddEven(int arr[], int size)
{
    printf("Even: ");
    for(int i = 0; i < size; i++)
        if(arr[i] % 2 == 0) printf("%d ", arr[i]);

    printf("\nOdd: ");
    for(int i = 0; i < size; i++)
        if(arr[i] % 2 != 0) printf("%d ", arr[i]);
    printf("\n");
}

void separatePosNeg(int arr[], int size)
{
    printf("Positive: ");
    for(int i = 0; i < size; i++)
        if(arr[i] >= 0) printf("%d ", arr[i]);

    printf("\nNegative: ");
    for(int i = 0; i < size; i++)
        if(arr[i] < 0) printf("%d ", arr[i]);
    printf("\n");
}
