#include <stdio.h>
#include <stdlib.h>
struct node {
    int coeff;
    int exp;
    struct node* next;
};
struct dnode {
    int coeff;
    int exp;
    struct dnode* prev;
    struct dnode* next;
};
struct cnode {
    int coeff;
    int exp;
    struct cnode* next;
};
struct node* insert(struct node* head, int c, int e) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    struct node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return head;
}
void display(struct node* head) {
    while (head != NULL) {
        printf("(%d,%d)", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
struct node* add(struct node* p1, struct node* p2) {
    struct node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            result = insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
struct node* multiply(struct node* p1, struct node* p2) {
    struct node* result = NULL;
    for (struct node* i = p1; i != NULL; i = i->next) {
        for (struct node* j = p2; j != NULL; j = j->next) {
            result = insert(result,
                            i->coeff * j->coeff,
                            i->exp + j->exp);
        }
    }
    return result;
}
struct dnode* insertDLL(struct dnode* head, int c, int e) {
    struct dnode* temp = (struct dnode*)malloc(sizeof(struct dnode));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
        return temp;
    struct dnode* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    return head;
}
struct dnode* reverseDLL(struct dnode* head) {
    struct dnode* temp = NULL;
    struct dnode* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}
void displayDLL(struct dnode* head) {
    while (head != NULL) {
        printf("(%d,%d)", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}
struct cnode* convertToCircular(struct dnode* head) {
    struct cnode* chead = NULL;
    struct cnode* tail = NULL;
    while (head != NULL) {
        struct cnode* temp = (struct cnode*)malloc(sizeof(struct cnode));
        temp->coeff = head->coeff;
        temp->exp = head->exp;
        temp->next = NULL;
        if (chead == NULL) {
            chead = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        head = head->next;
    }
    if (tail != NULL)
        tail->next = chead;  
    return chead;
}
void displayCircular(struct cnode* head) {
    if (head == NULL) return;
    struct cnode* temp = head;
    do {
        printf("(%d,%d) -> ", temp->coeff, temp->exp);
        temp = temp->next;
    } while (temp != head);
    printf("(back to (%d,%d))\n", head->coeff, head->exp);
}
int main() {
    struct node* P1 = NULL;
    struct node* P2 = NULL;
    P1 = insert(P1, 2, 2);
    P1 = insert(P1, 3, 1);
    P2 = insert(P2, 1, 1);
    P2 = insert(P2, 4, 0);
    printf("Addition: ");
    struct node* addResult = add(P1, P2);
    display(addResult);
    printf("Multiplication: ");
    struct node* mulResult = multiply(P1, P2);
    display(mulResult);
    struct dnode* dhead = NULL;
    while (mulResult != NULL) {
        dhead = insertDLL(dhead, mulResult->coeff, mulResult->exp);
        mulResult = mulResult->next;
    }
    dhead = reverseDLL(dhead);
    printf("Reversed DLL: ");
    displayDLL(dhead);
    struct cnode* chead = convertToCircular(dhead);
    printf("Circular List: ");
    displayCircular(chead);
    return 0;
}