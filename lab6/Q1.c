#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int evaluate(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (isdigit(arr[i][0]) || 
           (arr[i][0] == '-' && isdigit(arr[i][1]))) {
            push(atoi(arr[i]));
        }
        else {
            int op2 = pop();
            int op1 = pop();
            switch(arr[i][0]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}
int main() {
    char *arr[] = {"2", "3", "4", "*", "+", "5", "-"};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Result = %d\n", evaluate(arr, n));
    return 0;
}