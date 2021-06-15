//Running Sum of 1d Array

#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {

        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    for (int i = 1; i <= 5; i++)
        nums.push_back(i);

    nums = s.runningSum(nums);
}
