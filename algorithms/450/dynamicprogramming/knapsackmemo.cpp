#include <iostream>

using namespace std;

const int D = 1000; // DP - matrix dimension

int t[D][D]; // DP matrix

int knapsackDP(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    else if (t[n][W] != -1)
    {
        return t[n][W];
    }
    else
    {
        if (wt[n - 1] <= W)
        {
            t[n][W] = max(val[n - 1] + knapsackDP(wt, val, W - wt[n - 1], n - 1), knapsackDP(wt, val, W, n - 1));
        }
        else
        {
            t[n][W] = knapsackDP(wt, val, W, n - 1);
        }

        return t[n][W];
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50, n = 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            t[i][j] = -1;
        }
    }

    cout << knapsackDP(wt, val, W, n) << endl;
}