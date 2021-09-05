//Leet code Problem 20
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    stack<char> stack;
    bool isValid(string s) {
        for (char &ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }
                char _peeked = stack.top();
                if ((ch == ')' && _peeked == '(') || (ch == '}' && _peeked == '{') || (ch == ']' && _peeked == '['))
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};