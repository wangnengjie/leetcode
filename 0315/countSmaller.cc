#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<int> c;
    static auto lowbit(int i) -> int { return i & (-i); }
    void update(int i) {
        while (i < c.size()) {
            c[i]++;
            i += lowbit(i);
        }
    }
    auto query(int i) -> int {
        int count = 0;
        while (i > 0) {
            count += c[i];
            i -= lowbit(i);
        }
        return count;
    }

  public:
    vector<int> countSmaller(vector<int> &nums) {
        auto res = vector<int>(nums.size());
        vector<int> a;
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        auto pos = unique(a.begin(), a.end());

        int i = 1;
        auto map = unordered_map<int, int>();
        for (auto it = a.begin(); it != pos; it++, i++) {
            map[*it] = i;
        }

        c = vector<int>(nums.size() + 1, 0);
        for (i = nums.size() - 1; i >= 0; i--) {
            int rank = map[nums[i]];
            update(rank);
            res[i] = query(rank - 1);
        }
        return res;
    }
};