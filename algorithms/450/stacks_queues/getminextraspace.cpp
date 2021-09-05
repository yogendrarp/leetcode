#include <bits/stdc++.h>
#define maxsize 10

using namespace std;

struct minelstack
{
    int top = -1;
    int elements[maxsize];
    stack<int> minelements;

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
        if (top == maxsize - 1)
        {
            return true;
        }
        return false;
    }

    bool push(int elem)
    {
        if (isFull())
        {
            return false;
        }
        elements[++top] = elem;
        if (minelements.size() == 0 || elements[top] <= minelements.top())
        {
            minelements.push(elements[top]);
        }
        return true;
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        int item = elements[top--];
        if (item == minelements.top())
        {
            minelements.pop();
        }
        return true;
    }
};

int main()
{
    int arr[] = {18, 19, 25, 15, 16};
    minelstack minstack;
    minstack.push(18);
    minstack.push(19);
    minstack.push(25);
    minstack.push(18);
    minstack.push(15);
    minstack.push(16);

    minstack.pop();
    minstack.pop();
}