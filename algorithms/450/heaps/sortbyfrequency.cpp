#include <bits/stdc++.h>

using namespace std;

void sortbyfrequency(int arr[], int k, int size)
{
    map<int, int> frequency;
    for (int i = 0; i < size; i++)
    {
        frequency[arr[i]]++;
    }
    map<int, int>::iterator it;

    priority_queue<pair<int, int>> maxheap;

    for (it = frequency.begin(); it != frequency.end(); it++)
    {
        maxheap.push({it->second, it->first});
    }

    while (maxheap.size() > 0)
    {
        int frq = maxheap.top().first;
        int number = maxheap.top().second;

        for (int i = 0; i < frq; i++)
        {
            cout << number << " ";
        }
        maxheap.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 1, 3, 2, 4, 2, 4};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);
    sortbyfrequency(arr, k, size);
}