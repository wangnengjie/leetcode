#include <string>
#include <stack>
#include <algorithm>

using std::stack;
using std::string;

// class Solution
// {
// public:
//     int longestValidParentheses(string s)
//     {
//         int max = 0;
//         for (int left = 0, right = 0, i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(')
//                 left++;
//             else
//                 right++;
//             if (right > left)
//             {
//                 left = 0;
//                 right = 0;
//             }
//             else if (left == right && max < right)
//                 max = right;
//         }
//         for (int left = 0, right = 0, i = s.size() - 1; i >= 0; i--)
//         {
//             if (s[i] == '(')
//                 left++;
//             else
//                 right++;
//             if (right > left)
//             {
//                 left = 0;
//                 right = 0;
//             }
//             else if (left == right && max < right)
//                 max = right;
//         }
//         return max * 2;
//     }
// };

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> index;
        index.push(-1);
        int m = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                index.push(i);
            else
            {
                index.pop();
                if (index.empty())
                    index.push(i);
                else
                    m = std::max(m, i - index.top());
            }
        }
        return m;
    }
};