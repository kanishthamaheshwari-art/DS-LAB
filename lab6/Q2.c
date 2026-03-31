#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;
void push(char* str) {
    strcpy(stack[++top], str);
}
char* pop() {
    return stack[top--];
}
void prefixToPostfix(char* prefix) {
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char operand[2];
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(operand);
        }
        else {
            char op1[MAX], op2[MAX], temp[MAX];
            strcpy(op1, pop());
            strcpy(op2, pop());
            strcpy(temp, op1);
            strcat(temp, op2);
            int l = strlen(temp);
            temp[l] = prefix[i];
            temp[l+1] = '\0';
            push(temp);
        }
    }
    printf("Postfix Expression: %s\n", pop());
}
int main() {
    char prefix[] = "*+ABC";
    printf("Prefix Expression: %s\n", prefix);
    prefixToPostfix(prefix);
    return 0;
}