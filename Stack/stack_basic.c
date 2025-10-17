#include <stdio.h>
#include <stdbool.h>

#define STACK_CAPACITY 100

typedef struct Stack {
    int data[STACK_CAPACITY];
    int top;
} Stack;

void StackInit(Stack *s) {
    s->top = -1;
}

bool IsEmpty(const Stack *s) {
    return s->top == -1;
}

bool IsFull(const Stack *s) {
    return s->top == STACK_CAPACITY - 1;
}

int Size(const Stack *s) {
    return s->top + 1;
}

int Push(Stack *s, int data) {
    if(IsFull(s)) {
        fprintf(stderr, "Error : Stack overflow\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = data;
    return 1;
}

int Pop(Stack *s) {
    if(IsEmpty(s)) {
        fprintf(stderr, "Error : Stack is empty\n");
        return 0;
    }
    int poppedValue = s->data[s->top];
    s->top--;
    return poppedValue;
}

int Top(const Stack *s) {
    if(IsEmpty(s)) {
        fprintf(stderr, "Error : Stack is empty\n");
        return 0;
    }
    return s->data[s->top];
}

void Print(const Stack *s) {
     if(IsEmpty(s)) {
        fprintf(stderr, "Error : Stack is empty\n");
        return;
    }
    for(int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
}

int main() {
    Stack s;
    StackInit(&s);

    Push(&s, 2);  Print(&s);
    printf("\n");
    Push(&s, 5);  Print(&s);
    printf("\n");
    Push(&s, 10); Print(&s);
    printf("\n");

    printf("%d\n", Top(&s));
    Pop(&s);
    printf("%d\n", Top(&s));

    Pop(&s);    Print(&s);
    printf("\n");
    Pop(&s);    Print(&s);
    printf("\n");
    return 0;
}