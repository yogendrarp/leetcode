#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long> nextSmallerToRight(vector<long> inputs)
    {
        vector<long> nsr;
        stack<long> auxStack;
        for (int i = inputs.size(); i >= 0; i--)
        {

            if (auxStack.size() == 0)
            {
                nsr.push_back(-1);
            }
            else if (auxStack.size() > 0 && auxStack.top() < inputs[i])
            {
                nsr.push_back(auxStack.top());
            }
            else if (auxStack.size() > 0 && auxStack.top() >= inputs[i])
            {
                while (auxStack.size() > 0 && auxStack.top() >= inputs[i])
                {
                    auxStack.pop();
                }
                if (auxStack.size() > 0)
                {
                    nsr.push_back(auxStack.top());
                }
                else
                {
                    nsr.push_back(-1);
                }
            }
            auxStack.push(inputs[i]);
        }
        reverse(nsr.begin(), nsr.end());
        return nsr;
    }
};

int main()
{
    vector<long> inputs{4, 8, 5, 2, 25};
    Solution s;
    vector<long> op = s.nextSmallerToRight(inputs);
    cout << "End of Code";
}