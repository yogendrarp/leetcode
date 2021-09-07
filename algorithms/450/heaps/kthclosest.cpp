#include <bits/stdc++.h>

using namespace std;

void printkclosestelems(int arr[], int k, int x, int size)
{
    priority_queue<pair<long, int>> maxheap;

    for (int i = 0; i < size; i++)
    {
        maxheap.push({abs(arr[i] - x), arr[i]});
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }

    while (maxheap.size() > 0)
    {
        cout << maxheap.top().second << " ";
        maxheap.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int x = 8;
    int size = sizeof(arr) / sizeof(arr[0]);
    printkclosestelems(arr, k, x, size);
}