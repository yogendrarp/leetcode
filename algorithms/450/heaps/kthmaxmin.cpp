#include <bits/stdc++.h>

using namespace std;

int getKthMin(int arr[], int k, int size)
{
    priority_queue<int> maxheap;
    for (int i = 0; i < size; i++)
    {
        maxheap.push(arr[i]);
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }
    return maxheap.top();
}

int getKthMax(int arr[], int k, int size)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < size; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            minheap.pop();
        }
    }
    return minheap.top();
}

vector<int> klargestElements(int arr[], int k, int size)
{
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> largest;
    for (int i = 0; i < size; i++)
    {
        minheap.push(arr[i]);
        if (minheap.size() > k)
        {
            minheap.pop();
        }
    }
    while (minheap.size() > 0)
    {
        largest.push_back(minheap.top());
        minheap.pop();
    }
    return largest;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "3rd Min " << getKthMin(arr, k, size) << endl;
    cout << "3rd Max " << getKthMax(arr, k, size) << endl;
    vector<int> op = klargestElements(arr, k, size);
    cout << "debi" << endl;
}