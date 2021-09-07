#include <bits/stdc++.h>

using namespace std;

void printkclosesttoorigin(int points[][2], int k, int row, int col)
{
    priority_queue<pair<int, pair<int, int>>> maxheap;
    for (int i = 0; i < row; i++)
    {
        int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        maxheap.push({dist, {points[i][0], points[i][1]}});
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }
    while (maxheap.size() > 0)
    {
        cout << "Points (" << maxheap.top().second.first << "," << maxheap.top().second.second << ") are at a distance of " << maxheap.top().first << " from origin" << endl;
        maxheap.pop();
    }
}

int main()
{
    int points[4][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2, row = 4, col = 2;
    printkclosesttoorigin(points, k, row, col);
}