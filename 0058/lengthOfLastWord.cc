#include <string>

using std::string;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;
        int i = s.size() - 1;
        int white = 0;
        while (s[i] == ' ')
            i--, white++;

        for (; i >= 0; i--)
        {
            if (s[i] == ' ')
                break;
        }
        return s.size() - i - white - 1;
    }
};