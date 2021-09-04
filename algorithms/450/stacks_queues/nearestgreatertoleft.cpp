#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<long> getNearestGreaterToLeft(vector<long> input)
    {
        vector<long> ngL;
        stack<long> auxStack;

        for (int i = 0; i < input.size(); i++)
        {
            if (auxStack.size() == 0)
            {
                ngL.push_back(-1);
            }
            else if (auxStack.size() > 0 && auxStack.top() > input[i])
            {
                ngL.push_back(auxStack.top());
            }
            else if (auxStack.size() > 0 && auxStack.top() <= input[i])
            {
                while (auxStack.size() > 0 && auxStack.top() <= input[i])
                {
                    auxStack.pop();
                }
                if (auxStack.size() > 0)
                {
                    ngL.push_back(auxStack.top());
                }
                else
                {
                    ngL.push_back(-1);
                }
            }
            auxStack.push(input[i]);
        }
        return ngL;
    }
};

int main()
{
    vector<long> inputs{1, 3, 2, 4};
    Solution s;
    vector<long> op=s.getNearestGreaterToLeft(inputs);
    cout<<"end";
}