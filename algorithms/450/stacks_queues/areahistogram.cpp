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
            else if (auxStack1.size() > 0 && auxStack1.top().first > buildings[i])
            {
                while (auxStack1.size() > 0 && auxStack1.top().first > buildings[i])
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

        for (int i = buildings.size() - 1; i > 0; i--)
        {
            if (auxStack2.size() == 0)
            {
                smallestright.push_back(rightmaxindex);
            }
            else if (auxStack2.size() > 0 && auxStack2.top().first < buildings[i])
            {
                smallestright.push_back(auxStack2.top().second);
            }
            else if (auxStack2.size() > 0 && auxStack2.top().first > buildings[i])
            {
                while (auxStack2.size() > 0 && auxStack2.top().first > buildings[i])
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

        int maxarea = INT_MIN;
        for (int i = 0; i < buildings.size(); i++)
        {
            maxarea = max(maxarea, ((smallestright[i] - smallestleft[i] - 1) * buildings[i]));
        }
        return maxarea;
    }
};

int main()
{
    Solution s;
    vector<long> buildings{6, 2, 5, 4, 5, 1, 6};
    s.maxArea(buildings);
    cout << "";
}