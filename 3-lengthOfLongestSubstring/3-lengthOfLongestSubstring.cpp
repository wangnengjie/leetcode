#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution1
{
public:
  int lengthOfLongestSubstring(string s)
  {
    queue<char> Qchar;
    unordered_set<char> myset;
    int maxlength = 0;
    for (int i = 0; i < s.length(); i++)
    {
      char ch = s[i];
      if (myset.count(ch))
      {
        while (Qchar.front() != ch)
        {
          myset.erase(Qchar.front());
          Qchar.pop();
        }
        Qchar.pop();
        Qchar.push(ch);
      }
      else
      {
        Qchar.push(ch);
        myset.insert(ch);
        int length = Qchar.size();
        if (length > maxlength)
          maxlength = length;
      }
    }
    return maxlength;
  }
};

class Solution2
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> mymap;
    int maxlength = 0;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
      char ch = s[i];
      if (mymap.count(ch) && mymap[ch] >= j)
      {
        j = mymap[ch];
        mymap[ch] = i;
      }
      else
      {
        mymap[ch] = i;
        int length = i - j + 1;
        if (length > maxlength)
          maxlength = i - j + 1;
      }
    }
    return maxlength;
  }
};