#include <string>
#include <vector>

using std::string;
using std::vector;

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.empty())
//             return 0;
//         if (haystack.size() < needle.size())
//             return -1;
//         vector<vector<int>> table = ini(needle);
//         int next = 0;
//         for (int i = 0; i < haystack.size(); i++)
//         {
//             next = table[next][haystack[i]];
//             if (next == needle.size())
//                 return i - needle.size() + 1;
//         }
//         return -1;
//     }

//     vector<vector<int>> ini(const string &s)
//     {
//         vector<vector<int>> table(s.size(), vector<int>(256));
//         table[0][s[0]] = 1;
//         int x = 0;
//         for (int i = 1; i < s.size(); i++)
//         {
//             for (int j = 0; j < 256; j++)
//             {
//                 if (s[i] == j)
//                     table[i][j] = i + 1;
//                 else
//                     table[i][j] = table[x][j];
//             }
//             x = table[x][s[i]];
//         }
//         return table;
//     }
// };

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.empty())
//             return 0;
//         if (haystack.size() < needle.size())
//             return -1;
//         for (int i = 0; i < haystack.size(); i++)
//         {
//             int j = 0;
//             for (; j < needle.size(); j++)
//             {
//                 if (haystack[i + j] != needle[j])
//                     break;
//             }
//             if (j == needle.size())
//                 return i;
//         }
//         return -1;
//     }
// };
