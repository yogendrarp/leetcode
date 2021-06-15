#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max = *(max_element(candies.begin(), candies.end()));
        vector<bool> resp;
        for (int i = 0; i < candies.size(); i++)
        {
            if ((candies[i] + extraCandies) > = max)
            {
                resp.push_back(true);
            }
            else
            {
                resp.push_back(false);
            }
        }
        return resp;
    }
};

int main()
{
    Solution s;
    int extracandies = 3;

    int arr[] = {2, 3, 5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> vect(arr, arr + n);

    s.kidsWithCandies(vect, extracandies);
}