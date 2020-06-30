#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        auto res = vector<string>();
        if (s.size() < 4) {
            return res;
        }
        auto t = vector<string>(3);
        build(0, 0, s, t, res);
        return res;
    }

    void build(int idx, int s_idx, string &str, vector<string> &temp, vector<string> &res) {
        string sub;
        if (idx == 3) {
            if (s_idx >= str.size()) {
                return;
            }
            sub = str.substr(s_idx, str.size() - s_idx);
            if (sub.size() < 4 && stoi(sub) <= 255 && (sub[0] != '0' || sub.size() == 1)) {
                res.push_back(temp[0] + "." + temp[1] + "." + temp[2] + "." + sub);
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (s_idx + i > str.size()) {
                break;
            }
            sub = str.substr(s_idx, i);
            if ((i == 3 && stoi(sub) > 255) || (sub[0] == '0' && sub.size() != 1)) {
                break;
            }
            temp[idx] = sub;
            build(idx + 1, s_idx + i, str, temp, res);
        }
    }
};