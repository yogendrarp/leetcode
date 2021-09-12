#include <bits/stdc++.h>

using namespace std;

void towerofhanoi(int source, int dest, int helper, int n, int &count)
{
    count++;
    if (n == 1)
    {
        cout << "Moving plate " << n << " from " << source << " to " << dest << endl;
        return;
    }
    towerofhanoi(source, helper, dest, n - 1, count);
    cout << "Moving plate " << n << " from " << source << " to " << dest << endl;
    towerofhanoi(helper, dest, source, n - 1, count);
}

int main()
{
    int count = 0;
    towerofhanoi(0, 1, 2, 3, count);
    cout << "Count of shifts " << count << endl;
}