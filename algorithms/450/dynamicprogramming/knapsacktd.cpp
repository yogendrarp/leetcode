#include <iostream>

using namespace std;

int knapsackTd(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                t[i][j] = max(
                    val[i - 1] + t[i - 1][j - wt[i - 1]],
                    t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{
    int n = 4;
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;

    cout << knapsackTd(wt, val, W, n) << endl;
}