#include <bits/stdc++.h>

using namespace std;

void evaluate(string ip, string op)
{

    if (ip.length() == 0)
    {
        cout << "'" << op << "'" << endl;
        return;
    }
    string op1 = op;
    string op2 = op;

    if (isalpha(ip[0]))
    {
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
    }
    else
    {
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
    }
    ip.erase(ip.begin() + 0);

    evaluate(ip, op1);
    evaluate(ip, op2);
}

int main()
{
    string ip = "Ab12aB";
    string op = "";

    evaluate(ip, op);
}