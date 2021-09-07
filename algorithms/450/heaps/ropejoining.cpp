#include <bits/stdc++.h>

using namespace std;

void printmincost(int arr[], int size)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < size; i++)
    {
        minheap.push(arr[i]);
    }
    int cost = 0;
    while (minheap.size() != 0)
    {
        int a = minheap.top();
        minheap.pop();
        int b = minheap.top();
        minheap.pop();
        cost = a + b;
        minheap.push(cost);
    }

    cout << "The minimum cost is " << cost << endl;
}

int main()
{
    int ropelengths[] = {1, 2, 3, 4, 5};
    int size = sizeof(ropelengths) / sizeof(ropelengths[0]);
    printmincost(ropelengths, size);
}