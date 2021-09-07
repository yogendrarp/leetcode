#include <bits/stdc++.h>

using namespace std;

int kthsmallest(int arr[], int size, int k)
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

int main()
{
    int arr[] = {1, 3, 5, 11, 12, 15};
    int k1 = 3, k2 = 6;
    int k1thelem = kthsmallest(arr, 6, k1); //calculate size and use, too lazy tonight
    int k2thelem = kthsmallest(arr, 6, k2);
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > k1thelem && arr[i] < k2thelem)
        {
            sum += arr[i];
        }
    }

    cout << "Sum is " << sum << endl;
}
