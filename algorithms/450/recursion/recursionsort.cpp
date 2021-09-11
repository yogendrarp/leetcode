#include <bits/stdc++.h>
using namespace std;

void insertionSortRecursive(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }

    insertionSortRecursive(arr, size - 1);
    int last = size - 1;
    int j = size - 2;

    while(j>=0 && arr[j] > last){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSortRecursive(arr, size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}