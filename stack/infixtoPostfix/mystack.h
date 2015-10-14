#ifndef STACK_H
#include "stdlib.h"
#define N 10
#define ERROR -999999

class Stack
{
private:
    int* s;
    int top;
    int capacity;
public:
    Stack(int capacity);
    Stack();
    ~Stack();
    bool push(int item);
    int pop();
    int pick();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int capacity)
{
    this->s=(int*)malloc(sizeof(int)*(capacity));
    this->capacity=capacity;
    this->top=-1;
}

Stack::Stack()
{
    this->s=(int*)malloc(sizeof(int)*N);
    this->capacity=N;
    this->top=-1;
}

Stack::~Stack()
{
    delete s;
}

bool Stack::push(int item)
{
    if(this->isFull())
        return false;
    this->s[++(this->top)]=item;
    return true;
}

int Stack::pop()
{
    if(this->isEmpty())
        return ERROR;
    return this->s[this->top--];
}

int Stack::pick()
{

    if(this->isEmpty())
        return ERROR;
    return this->s[this->top];
}

bool Stack::isEmpty()
{
    if(this->top==-1)
        return true;
    else
        return false;
}

bool Stack::isFull()
{
    if(this->top==this->capacity-1)
        return true;
    else
        return false;
}

#endif // STACK_H
