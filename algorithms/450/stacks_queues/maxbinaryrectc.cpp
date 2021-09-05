#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long maxArea(vector<long> buildings)
    {
        int leftleastindex = -1;
        int rightmaxindex = buildings.size();
        vector<long> smallestleft, smallestright;
        stack<pair<long, int>> auxStack1, auxStack2;
        //smallest left
        for (int i = 0; i < buildings.size(); i++)
        {
            if (auxStack1.size() == 0)
            {
                smallestleft.push_back(leftleastindex);
            }
            else if (auxStack1.size() > 0 && auxStack1.top().first < buildings[i])
            {
                smallestleft.push_back(auxStack1.top().second);
            }
            else if (auxStack1.size() > 0 && auxStack1.top().first >= buildings[i])
            {
                while (auxStack1.size() > 0 && auxStack1.top().first >= buildings[i])
                {
                    auxStack1.pop();
                }
                if (auxStack1.size() == 0)
                {
                    smallestleft.push_back(leftleastindex);
                }
                else
                {
                    smallestleft.push_back(auxStack1.top().second);
                }
            }
            auxStack1.push({buildings[i], i});
        }

        for (int i = buildings.size() - 1; i >= 0; i--)
        {
            if (auxStack2.size() == 0)
            {
                smallestright.push_back(rightmaxindex);
            }
            else if (auxStack2.size() > 0 && auxStack2.top().first < buildings[i])
            {
                smallestright.push_back(auxStack2.top().second);
            }
            else if (auxStack2.size() > 0 && auxStack2.top().first >= buildings[i])
            {
                while (auxStack2.size() > 0 && auxStack2.top().first >= buildings[i])
                {
                    auxStack2.pop();
                }
                if (auxStack2.size() == 0)
                {
                    smallestright.push_back(rightmaxindex);
                }
                else
                {
                    smallestright.push_back(auxStack2.top().second);
                }
            }
            auxStack2.push({buildings[i], i});
        }

        reverse(smallestright.begin(), smallestright.end());

        long maxarea = LONG_MIN;
        for (int i = 0; i < buildings.size(); i++)
        {
            long area = (smallestright[i] - smallestleft[i] - 1) * buildings[i];
            if (maxarea < area)
            {
                maxarea = area;
            }
        }
        return maxarea;
    }

    long maxBin(vector<vector<int>> twodarray)
    {
        vector<long> size;
        for (int i = 0; i < twodarray[0].size(); i++)
        {
            size.push_back(twodarray[0][i]);
        }

        long maxarea = maxArea(size);

        for (int i = 1; i < twodarray.size(); i++)
        {
            for (int j = 0; j < twodarray[i].size(); j++)
            {
                if (twodarray[i][j] == 1)
                {
                    size[j] += 1;
                }
                else
                {
                    size[j] = 0;
                }
            }
            long result = maxArea(size);
            if (result > maxarea)
            {
                maxarea = result;
            }
        }
        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<int> row1{0, 1, 1, 0};
    vector<int> row2{1, 1, 1, 1};
    vector<int> row3{1, 1, 1, 1};
    vector<int> row4{1, 1, 0, 0};

    vector<vector<int>> twodarry;
    twodarry.push_back(row1);
    twodarry.push_back(row2);
    twodarry.push_back(row3);
    twodarry.push_back(row4);

    s.maxBin(twodarry);
    cout << "";
}