#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    string frequencySort(string s)
    {
        if (s.size() < 3)
            return s;
        unordered_map<char, int> charMap;
        for (const auto &c : s)
            charMap[c]++;
        auto compair = [](pair<char, int> a, pair<char, int> b) { return a.second < b.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compair)> pqueue(compair);
        for (const auto &i : charMap)
            pqueue.push(i);
        string re("");
        while (!pqueue.empty())
        {
            re += string(pqueue.top().second, pqueue.top().first);
            pqueue.pop();
        }
        return re;
    }
};