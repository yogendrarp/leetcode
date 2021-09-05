#include <bits/stdc++.h>

class DLLNode
{
public:
    DLLNode *prevptr;
    DLLNode *nextptr;
    int data;
};

class Stack
{
public:
    DLLNode *header;
    DLLNode *mid;
    int count;
};

Stack *createStack()
{
    Stack *stack = new Stack();
    stack->count = 0;
    return stack;
}

int findMiddle(Stack *stack)
{
    if (stack->count == 0)
    {
        return -1;
    }
    return stack->mid->data;
}

int deleteMiddle(Stack *stack)
{
    int element = stack->mid->data;
    stack->mid->prevptr->nextptr = stack->mid->nextptr;
    stack->mid->nextptr->prevptr = stack->mid->prevptr->nextptr;

    delete stack->mid;
    stack->mid = stack->mid->nextptr;
    return element;
}

void push(Stack *stack, int data)
{
    DLLNode *new_dll_node = new DLLNode();
    new_dll_node->data = data;
    new_dll_node->prevptr = NULL;
    new_dll_node->nextptr = stack->header;
    stack->count++;

    if (stack->count == 1)
    {
        stack->mid = new_dll_node;
    }
    else{
        stack->header->prevptr = new_dll_node;
        if(!(stack->count&1)){
            stack->mid=stack->mid->prevptr;
        }
    }
    stack->header = new_dll_node;
}

int pop(Stack *stack){
    if(stack->count==0){
        return -1;
    }

    DLLNode * head = stack->header;
    int data = head->data;
    stack->header = stack->header->nextptr;
    if(stack->header!=NULL){
        stack->header->prevptr=NULL;
    }
    stack->count -= 1;
 
    if ((stack->count) & 1)
        stack->mid = stack->mid->nextptr;
 
    free(head);
 
    return data;
}