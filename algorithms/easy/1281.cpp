
#include <iostream>
using namespace std;
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0, prod = 1;

        while (n != 0)
        {
            int dig = n % 10;
            prod *= dig;
            sum += dig;
            n /= 10;
        }

        return prod - sum;
    }
};

int main()
{
    Solution s1;
    cout << s1.subtractProductAndSum(234) << endl;
}