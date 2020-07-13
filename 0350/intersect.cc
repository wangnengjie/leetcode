#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        auto res = vector<int>();
        if (nums1.empty() || nums2.empty()) {
            return res;
        }
        auto &a = nums1.size() < nums2.size() ? nums1 : nums2;
        auto &b = nums1.size() < nums2.size() ? nums2 : nums1;
        auto map = unordered_map<int, int>();
        for (auto &v : a) {
            map[v]++;
        }
        for (auto &v : b) {
            if (map[v] != 0) {
                res.push_back(v);
                map[v]--;
            }
        }
        return res;
    }
};