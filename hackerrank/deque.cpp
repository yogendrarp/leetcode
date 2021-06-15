#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    int run = 0;
    deque<int> max;
    for (int i = 0; i < n; i++)
    {
        if (run == 0)
        {
            max.push_back(arr[i]);
        }
        else if (run < k)
        {
            int curmax = max.back();
            if (arr[i] > curmax)
            {
                max.pop_back();
                max.push_back(arr[i]);
            }
        }
        run++;
        if (run == k)
        {
            if (i != n - 1)
            {
                i = i - (k - 1);
            }
            run = 0;
        }
    }
   
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}