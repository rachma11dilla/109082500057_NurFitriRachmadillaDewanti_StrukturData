#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack {
    int info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S); // Latihan 1
void pushAscending(Stack &S, int x); // Latihan 2
void getInputStream(Stack &S); // Latihan 3

#endif