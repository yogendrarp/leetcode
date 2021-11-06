#include <iostream>

using namespace std;

bool subSetSum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                t[i][j] == false;
            }
            else if (j == 0)
            {
                t[i][j] == true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    int sum = 6;
    int arr[] = {2, 3, 7, 8};
    int n = 4;
    subSetSum(arr, sum, n) ? cout << "Yes" : cout << "No";
}