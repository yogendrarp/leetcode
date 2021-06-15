#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int numbers[101] = {0};
        vector<int> vect2;

        vect2 = nums;
        sort(nums.begin(), nums.end());
        int lastnum = nums[0];
        int currSmall = 0;
        int samecount = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > lastnum)
            {
                currSmall++;
                currSmall += samecount;
                samecount = 0;
                lastnum = nums[i];
            }
            else if (nums[i] == lastnum)
            {
                samecount++;
            }
            numbers[nums[i]] = currSmall;
        }

        vector<int> count;
        for (int i = 0; i < vect2.size(); i++)
        {
            count.push_back(numbers[vect2[i]]);
        }

        return count;
    }
};

int main()
{
    static const int arr[] = {8, 1, 2, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution s1;
    s1.smallerNumbersThanCurrent(vec);
}