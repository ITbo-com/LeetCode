#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if (s1.empty())
                {
                    s1.push(s[i]);
                    break;
                }
                if (s[i] == ')')
                {
                    if (s1.top() == '(')
                        s1.pop();
                    else
                        break;
                }
                else if (s[i] == '}')
                {
                    if (s1.top() == '{')
                        s1.pop();
                    else
                        break;
                }
                else if (s[i] == ']')
                {
                    if (s1.top() == '[')
                        s1.pop();
                    else
                        break;
                }
                else
                    break;
            }
        }

        if (s1.empty())
            return true;
        else
            return false;

    }
};
