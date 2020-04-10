#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> count(s.size() + 1);
        count[0] = 1;
        count[1] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
                if ((s[i - 1] == '2' || s[i - 1] == '1'))
                    count[i + 1] = count[i - 1];
                else
                    return 0;
            else if ((s[i] <= '9' && s[i - 1] == '1') || (s[i] <= '6' && s[i - 1] == '2'))
                count[i + 1] = count[i - 1] + count[i];
            else
                count[i + 1] = count[i];
        }
        return count.back();
    }
};

// class Solution
// {
// public:
//     int numDecodings(string s)
//     {
//         if (s[0] == '0')
//             return 0;
//         int pre = 1, cur = 1;
//         for (int i = 1, temp; i < s.size(); i++)
//         {
//             temp = cur;
//             if (s[i] == '0')
//                 if ((s[i - 1] == '2' || s[i - 1] == '1'))
//                     cur = pre;
//                 else
//                     return 0;
//             else if ((s[i] <= '9' && s[i - 1] == '1') || (s[i] <= '6' && s[i - 1] == '2'))
//                 cur = pre + cur;
//             else
//                 cur = cur;
//             pre = temp;
//         }
//         return cur;
//     }
// };