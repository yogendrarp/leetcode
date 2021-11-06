#include <iostream>

using namespace std;

int subsetSumCount(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "____________________________________________" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    for (int k = 0; k < n + 1; k++)
    {
        for (int m = 0; m < sum + 1; m++)
        {
            cout << t[k][m] << "\t";
        }
        cout << endl;
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 1, 4, 5};
    int sum = 7, n = 6;
    subsetSumCount(arr, sum, n);
    //cout << "Count is: " << subsetSumCount(arr, sum, n) << endl;
}