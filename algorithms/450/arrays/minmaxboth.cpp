#include <bits/stdc++.h>

using namespace std;

struct minmaxboth
{
    int min;
    int max;
};

minmaxboth getminmax(int arr[], int size)
{
    minmaxboth both;
    int i;
    both.max = arr[0];
    both.min = arr[0];
    if (size == 1)
    {
        return both;
    }
    else if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            both.max = arr[0];
            both.min = arr[1];
        }
        else if (arr[1] > arr[0])
        {
            both.max = arr[1];
            both.min = arr[0];
        }
        else
        {
            both.max = arr[0];
            both.min = arr[0];
        }
    }
    else
    {
        for (int i = 2; i < size; i++)
        {
            if (arr[i] > both.max)
            {
                both.max = arr[i];
            }
            else if (arr[i] < both.min)
            {
                both.min = arr[i];
            }
        }
    }
    return both;
}

minmaxboth getminmaxbinary(int arr[], int low, int high)
{

    minmaxboth minmax, left, right;
    int mid;
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else if (arr[low] < arr[high])
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        else
        {
            minmax.max = arr[low];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    left = getminmaxbinary(arr, low, mid);
    right = getminmaxbinary(arr, mid + 1, high);

    if (left.min < right.min)
    {
        minmax.min = left.min;
    }
    else
    {
        minmax.min = right.min;
    }

    if (left.max > right.max)
    {
        minmax.max = left.max;
    }
    else
    {
        minmax.max = right.max;
    }

    return minmax;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 9, 8};
    // minmaxboth both = getminmax(arr, 6);
    // cout << both.max << ", " << both.min << endl;

    minmaxboth bin = getminmaxbinary(arr, 0, 6);
    cout << bin.max << "# " << bin.min << endl;
}