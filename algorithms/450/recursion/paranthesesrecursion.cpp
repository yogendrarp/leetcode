#include <bits/stdc++.h>

using namespace std;

void evalaute(int open, int close, string op)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        evalaute(--open, close, op1);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        evalaute(open, --close, op2);
    }
}

int main()
{
    int n = 3;
    int open = n, close = n;
    string op = "";
    evalaute(open, close, op);
}