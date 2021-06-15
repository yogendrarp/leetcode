#include <vector>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> samenumbers;

        int currnum = nums[0];
        int currcount = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == currnum)
            {
                currcount += 1;
            }
            else
            {
                samenumbers.push_back(currcount);
                currcount = 1;
                currnum = nums[i];
            }
        }
        samenumbers.push_back(currcount);

        int count = 0;
        for (int i = 0; i < samenumbers.size(); i++)
        {
            count += ((samenumbers[i] * (samenumbers[i] - 1) / 2));
        }

        return count;
    }
};

int main()
{
    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    Solution s;
    s.numIdenticalPairs(vect);
}