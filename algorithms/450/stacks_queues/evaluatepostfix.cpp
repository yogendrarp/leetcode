#include <bits/stdc++.h>

using namespace std;

// works for single digit only
long evalexp(string exp)
{

    stack<int> operands;
    for (int i = 0; i < exp.size(); i++)
    {
        char op = exp[i];
        if ((op >= '0' && op <= '9'))
        {
            operands.push((int)op-48);
        }
        else
        {

            int num1 = operands.top();
            operands.pop();
            int num2 = operands.top();
            operands.pop();
            int result;
            if (op == '+')
            {
                result = num1 + num2;
            }
            else if (op == '-')
            {
                result = num1 - num2;
            }
            else if (op == '*')
            {
                result = num1 * num2;
            }
            else if (op == '/')
            {
                result = num1 / num2;
            }
            operands.push(result);
        }

    }
    return operands.top();
}

int main()
{
    string postfixexp = "24+46+*";
    long result = evalexp(postfixexp);
    cout << result;
}