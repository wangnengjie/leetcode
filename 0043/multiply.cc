#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        int n1len = num1.size(), n2len = num2.size();
        vector<int> carry(n2len, 0);
        string result(n1len + n2len, '0');
        int g = 0, i = 0;
        for (bool f = false; !f; i++)
        {
            int temp = 0;
            for (int j = n2len - 1; j >= 0 && j + i >= n2len - 1; j--)
            {
                int base = n1len - i + (n2len - j - 2);
                if (base < -1)
                    continue;
                if (base < 0)
                {
                    if (j == 0)
                        f = true;
                    if (carry[j] != 0)
                    {
                        temp += carry[j];
                        carry[j] = 0;
                    }
                }
                else
                {
                    int re = (num1[base] - '0') * (num2[j] - '0') + carry[j];
                    carry[j] = re / 10;
                    temp += re % 10;
                }
            }
            result[result.size() - i - 1] = (temp + g) % 10 + '0';
            g = (temp + g) / 10;
        }
        result = result.substr(std::find_if_not(result.begin(), result.end(), [](const char &c) { return c == '0'; }) - result.begin());
        return result;
    }
};
