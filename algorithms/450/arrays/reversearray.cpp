#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int start = 0;
    int end = 5; //size-1
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}