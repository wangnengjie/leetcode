#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        // int min = dungeon[0][0];
        int M = dungeon.size();
        int N = dungeon[0].size();
        auto trace = vector<int>(N + 1, INT_MAX);
        trace[N - 1] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                trace[j] = std::max(std::min(trace[j], trace[j + 1]) - dungeon[i][j], 1);
            }
        }
        return trace[0];
    }
};