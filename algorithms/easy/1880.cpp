//Check if Word Equals Summation of Two Words
#include <string>
#include <iostream>
using namespace std;
class Solution
{
    int get_numeric_word(std::string word)
    {
        int value = 0;
        for (int i = 0; i < word.length(); i++)
        {
            value = (value * 10) + word[i] - 'a';
        }
        return value;
    }

public:
    bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord)
    {
        int _fw = get_numeric_word(firstWord);
        int _sw = get_numeric_word(secondWord);
        int _tw = get_numeric_word(targetWord);
        return _fw + _sw == _tw;
    }
};

int main()
{
    Solution s;
    std::cout << s.isSumEqual("abcd", "efgh", "abc") << std::endl;
}
