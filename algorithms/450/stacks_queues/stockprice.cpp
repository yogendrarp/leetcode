#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<long> getStockSpan(vector<long> inputs)
    {
        vector<long> stockSpan;
        stack<pair<long, int>> auxStack;
        for (int i = 0; i < inputs.size(); i++)
        {
            if (auxStack.size() > 0 && auxStack.top().first > inputs[i])
            {
                stockSpan.push_back(auxStack.top().second);
            }
            else if (auxStack.size() < 1)
            {
                stockSpan.push_back(-1);
            }
            else if (auxStack.size() > 0 && auxStack.top().first <= inputs[i])
            {
                while (auxStack.size() > 0 && auxStack.top().first <= inputs[i])
                {
                    auxStack.pop();
                }
                if (auxStack.size() == 0)
                {
                    stockSpan.push_back(-1);
                }
                else
                {
                    stockSpan.push_back(auxStack.top().second);
                }
            }
            auxStack.push({inputs[i], i});
        }
        for (int i = 0; i < stockSpan.size(); i++)
        {
            stockSpan[i]=i-stockSpan[i];
        }
        return stockSpan;
    }
};

int main(){

    Solution s;
    vector<long> inputs{100,80,60,70,120,75,85};
    vector<long> op=s.getStockSpan(inputs);
    cout<<"";
}