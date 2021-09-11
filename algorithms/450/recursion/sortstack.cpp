#include <bits/stdc++.h>
#define maxsize 10

using namespace std;

struct sortedstack
{
    int top = -1;
    int elements[maxsize];

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
        if ((top + 1) == maxsize)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return (top + 1);
    }

    bool push(int data)
    {
        if (isFull())
        {
            return false;
        }
        elements[++top] = data;
        return true;
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        --top;
        return true;
    }

    int peek()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return elements[top];
    }

    void sortedInsert(int x)
    {
        if (isEmpty() || x >= peek())
        {
            push(x);
            return;
        }
        int temp = peek();
        pop();
        sortedInsert(x);
        push(temp);
    }

    void sortstack()
    {
        if (!isEmpty())
        {
            int x = peek();
            pop();
            sortstack();
            sortedInsert(x);
        }
    }
};

int main()
{
    struct sortedstack st;
    st.push(10);
    st.push(7);
    st.push(20);
    st.push(13);
    st.push(53);

    st.sortstack();

    cout << "Debug" << endl;
}