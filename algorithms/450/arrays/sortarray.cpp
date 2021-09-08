#include <bits/stdc++.h>

using namespace std;
int main()
{
    int arr[] = {0, 1, 2, 1, 0, 0, 1, 2, 0, 1};
    int z_count = 0, o_count = 0, t_count = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        switch (arr[i])
        {
        case 0:
            z_count++;
            break;
        case 1:
            o_count++;
            break;
        case 2:
            t_count++;
            break;
        }
    }

    while (z_count > 0)
    {
        cout << 0 << " ";
        z_count--;
    }

    while (o_count > 0)
    {
        cout << 1 << " ";
        o_count--;
    }

    while (t_count > 0)
    {
        cout << 2 << " ";
        t_count--;
    }
}