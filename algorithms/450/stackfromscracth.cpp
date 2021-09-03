#include <iostream>
#define MAX_SIZE 10

using namespace std;

struct Stack
{
    int top = -1;
    long elements[MAX_SIZE];

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == MAX_SIZE)
        {
            return true;
        }
        return false;
    }

    bool push(long element)
    {
        if (isFull())
        {
            return false;
        }
        elements[++top]=element;
        return true;
    }

    long peek(){
        if(!isEmpty()){
            return elements[top];
        }else{
            return -1000;
        }
    }

    long pop(){
        if(isEmpty()){
            return -1000;
        }
        return elements[top--];
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.peek()<<endl;

    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }

}