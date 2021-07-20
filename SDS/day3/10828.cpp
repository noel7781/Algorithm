#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Stack {
    int data;
    struct _Stack *next;
}Stack;

Stack* CreateStack() {
    Stack *newStack = (Stack *)malloc(sizeof(Stack *));
    newStack->data = -1;
    newStack->next = NULL;
    return newStack;
}

int retTop(Stack *base) {
    Stack *p = base;
    if(p->next == NULL) return -1;
    while(p->next != NULL) {
        p = p->next;
    }
    return p->data;
}

int retSize(Stack *base) {
    Stack *p = base;
    int count = 0;
    if(p->next == NULL) return 0;
    while(p->next != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

int retEmpty(Stack *base) {
    if(base->next == NULL) return 1;
    return 0;
}

void push(Stack* base, int data) {
    Stack *nStack = (Stack *)malloc(sizeof(Stack *));
    nStack->data = data;
    nStack->next = NULL;
    Stack *p = base;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = nStack;
}

int pop(Stack *base) {
    Stack *p = base;
    Stack *q = p;
    int ret = 0;
    if(p->next == NULL) return -1;
    while(p->next != NULL) {
        q = p;
        p = p->next;
    }
    ret = p->data;
    q->next = NULL;
    free(p);
    p = NULL;
    return ret;
}

int main() {
    Stack* S = CreateStack();
    int orderCount = 0;
    char* input = malloc(sizeof(char) * 100);
    scanf("%d", &orderCount);
    for(int i = 0; i < orderCount; i++) {
        scanf("%s", input);
        if(strcmp(input, "push") == 0) {
            int data;
            scanf("%d", &data);
            push(S, data);
        } else if(strcmp(input, "top") == 0) {
            printf("%d\n",retTop(S));
        } else if(strcmp(input, "size") == 0) {
            printf("%d\n",retSize(S));
        } else if(strcmp(input, "empty") == 0) {
            printf("%d\n",retEmpty(S));
        } else if(strcmp(input, "pop") == 0) {
            printf("%d\n",pop(S));
        }
    }
    return 0;
}