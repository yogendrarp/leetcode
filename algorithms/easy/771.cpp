#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int alphabets[52] = {0};
        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {

            if (isupper(stones[i]))
            {
                alphabets[(int)stones[i] - 39]++;
            }
            else
            {
                alphabets[(int)stones[i] - 97]++;
            }
        }

        for (int i = 0; i < jewels.size(); i++)
        {
            if (isupper(jewels[i]))
            {
                count += alphabets[(int)jewels[i] - 39];
            }
            else
            {
                count += alphabets[(int)jewels[i] - 97];
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout<<s.numJewelsInStones("z", "ZZ");
}