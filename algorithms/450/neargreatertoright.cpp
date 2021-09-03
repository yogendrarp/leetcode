#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<long> nextGreaterElement(vector<long> array)
    {
        stack<long> auxStack;
        vector<long> ngr;
        int size = array.size();

        for (int i = size - 1; i >= 0; i--)
        {
            if (auxStack.size() == 0)
            {
                ngr.push_back(-1);
            }
            else if (auxStack.size() > 0 && auxStack.top() > array[i])
            {
                ngr.push_back(auxStack.top());
            }
            else if (auxStack.size() > 0 && auxStack.top() <= array[i])
            {
                while (auxStack.size() > 0 && auxStack.top() <= array[i])
                {
                    auxStack.pop();
                }
                if (auxStack.empty())
                {
                    ngr.push_back(-1);
                }
                else
                {
                    ngr.push_back(auxStack.top());
                }
            }
            auxStack.push(array[i]);
        }
        reverse(ngr.begin(), ngr.end());
        return ngr;
    }
};

int main()
{
    Solution s;
    vector<long> input{1, 2, 3, 4};
    vector<long> op = s.nextGreaterElement(input);
}