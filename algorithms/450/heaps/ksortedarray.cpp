#include <bits/stdc++.h>

using namespace std;

void getksortedarray(int arr[], int k, int size)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            arr[index++] = minheap.top();
            minheap.pop();
        }
    }
    while (!minheap.empty())
    {
        arr[index++] = minheap.top();
        minheap.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    getksortedarray(arr, k, size);
    cout << "pointer";
}