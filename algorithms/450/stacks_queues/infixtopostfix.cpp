#include <bits/stdc++.h>

using namespace std;

int pres(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string infixToPostFix(string exp)
{
    string evald;
    stack<char> operat;
    for (int i = 0; i < exp.size(); i++)
    {
        char op = exp[i];
        if ((op >= 'a' && op <= 'z') || (op > 'A' && op <= 'Z') || (op >= '0' && op <= '9'))
            evald += op;
        else if (op == '(')
        {
            operat.push('(');
        }
        else if (op == '(')
        {
            while (operat.top() != '(')
            {
                evald += operat.top();
                operat.pop();
            }
            operat.pop();
        }
        else
        {
            while (!operat.empty() && pres(op) <= pres(operat.top()))
            {
                evald += operat.top();
                operat.pop();
            }
            operat.push(op);
        }
    }
    while (!operat.empty())
    {
        evald += operat.top();
        operat.pop();
    }

    return evald;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string evalExp = infixToPostFix(exp);
    cout<<evalExp;
}