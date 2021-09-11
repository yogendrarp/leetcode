#include <bits/stdc++.h>

using namespace std;

set<string> uniqueentries;

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        uniqueentries.insert(op);
        return;
    }

    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}

int main()
{
    string ip = "aab";
    string op = "";
    solve(ip, op);
    set<string>::iterator it;
    for (it = uniqueentries.begin(); it != uniqueentries.end(); it++)
    {
        cout << *it << endl;
    }
}