#include <bits/stdc++.h>

using namespace std;

void topkfrequency(int arr[], int k, int size)
{
    map<int, int> frequency;
    for (int i = 0; i < size; i++)
    {
        frequency[arr[i]]++;
    }
    map<int, int>::iterator it;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

    for (it = frequency.begin(); it != frequency.end(); it++)
    {
        minheap.push({it->second, it->first});
        if (minheap.size() > k)
        {
            minheap.pop();
        }
    }

    while (minheap.size() > 0)
    {
        cout << minheap.top().second << " has frequency of " << minheap.top().first << endl;
        minheap.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 4, 2, 4};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    topkfrequency(arr, k, size);
}