#include <bits/stdc++.h>

using namespace std;

long getwaterharvested(int arr[], int size)
{
    int maxleft[size];
    maxleft[0] = arr[0];
    for (int i = 1; i < size; i++)
    {
        maxleft[i] = max(maxleft[i - 1], arr[i]);
    }
    int maxright[size];
    maxright[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        maxright[i] = max(maxright[i + 1], arr[i]);
    }

    int water[size], sum = 0;
    for (int i = 0; i < size; i++)
    {
        water[i] = min(maxleft[i], maxright[i]) - arr[i];
        sum += water[i];
    }
    return sum;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    long watercollected = getwaterharvested(arr, 6);
    cout << watercollected << endl;
}