#include <cstddef>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    string minWindow(string s, string t) {
        string res;
        if (s.empty() || t.empty() || t.size() > s.size()) {
            return res;
        }
        auto map1 = unordered_map<char, int>();
        auto map2 = unordered_map<char, int>();
        int count = 0;
        auto len_t = t.size();
        for (auto &c : t) {
            map1[c]++;
        }
        for (size_t left = 0, right = 0; right < s.size();) {
            auto c = s.at(right);
            right++;
            if (map1.find(c) == map1.end()) {
                continue;
            }
            map2[c]++;
            if (map2[c] <= map1[c]) {
                count++;
            }
            if (count == t.size()) {
                while (true) {
                    auto c_l = s.at(left);
                    left++;
                    if (map1.find(c_l) == map1.end()) {
                        continue;
                    }
                    map2[c_l]--;
                    if (map2[c_l] < map1[c_l]) {
                        count--;
                        auto len = right - left + 1;
                        if (res.empty() || len < res.size()) {
                            res = s.substr(left - 1, len);
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};