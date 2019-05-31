#include <string>
using namespace std;
class Solution
{
public:
  int count(string s, int left, int right)
  {
    while (left >= 0 && right < s.length() && s.at(left) == s.at(right))
    {
      left--;
      right++;
    }
    return right - left - 1;
  }

  string longestPalindrome(string s)
  {
    if (s.length() < 1)
      return "";
    int start = 0, end = 0;
    int len1, len2, len;
    for (int i = 0; i < s.length(); i++)
    {
      len1 = count(s, i, i);
      len2 = count(s, i, i + 1);
      len = len1 > len2 ? len1 : len2;
      if (len > end - start)
      {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }
};