#include <vector>
using std::vector;

class Solution {
  public:
    vector<int> countBits(int num) {
        auto res = vector<int>(num + 1);
        if (num == 0) {
            return res;
        }
        res[1] = 1;
        for (int i = 2, g = 2; i < res.size(); i++) {
            if (i == (g << 1)) {
                g <<= 1;
            }
            res[i] = 1 + res[i - g];
        }
        return res;
    }
};