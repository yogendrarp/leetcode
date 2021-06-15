#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string resp = "";
        for (int i = 0; i < indices.size(); i++)
        {
            resp[indices[i]]=s[i];
        }

        return resp;
    }
};

int main()
{
    int array[] = {4, 5, 6, 7, 0, 2, 1, 3};
    vector<int> vec(array, array + sizeof(array) / sizeof(array[0]));
    Solution s;
    s.restoreString("codeleet", vec);
}