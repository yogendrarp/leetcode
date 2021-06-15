#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(nums[i]);
            temp.push_back(nums[n + i]);
        }
        return temp;
    }
};

int main()
{
    Solution s;

    int arr[] = {2, 5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> vect(arr, arr + n);
    s.shuffle(vect, 3);
}