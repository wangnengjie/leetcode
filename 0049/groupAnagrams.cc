#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::vector;

// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs)
//     {
//         auto strMap = unordered_map<string, vector<string>>();
//         auto letterTable = vector<int>(26);
//         for (const auto &str : strs)
//         {
//             std::fill(letterTable.begin(), letterTable.end(), 0);
//             for (const auto &c : str)
//                 letterTable[c - 'a']++;
//             string key("");
//             for (const auto &num : letterTable)
//                 key += "#" + std::to_string(num);
//             strMap[key].push_back(str);
//         }
//         auto re = vector<vector<string>>();
//         re.reserve(strMap.size());
//         for (const auto &i : strMap)
//             re.push_back(i.second);
//         return re;
//     }
// };

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        auto strMap = unordered_map<string, vector<string>>();
        for (const auto &str : strs)
        {
            string temp(str);
            std::sort(temp.begin(), temp.end());
            strMap[temp].push_back(str);
        }
        auto re = vector<vector<string>>();
        re.reserve(strMap.size());
        for (const auto &i : strMap)
            re.push_back(i.second);
        return re;
    }
};