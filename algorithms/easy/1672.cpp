#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution
{
public:
    int maximumWealth(vector<vector<int> > &accounts)
    {
        int maxSum = accumulate(accounts[0].begin(), accounts[0].end(), 0);
        for (int i = 1; i < accounts.size(); i++)
        {
            int _temp = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            if (maxSum < _temp)
            {
                maxSum = _temp;
            }
        }
        return maxSum;
    }
};

int main()
{

    static const int arr[] = {16, 2, 77, 29};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    static const int arr1[] = {1, 2, 77, 29};
    vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));

    vector<vector<int> > temp;
    temp.push_back(vec);
    temp.push_back(vec1);
    Solution s1;
    s1.maximumWealth(temp);
}