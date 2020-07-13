#include <vector>
using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int pos = 0;
        int all = 0;
        int n = gas.size();
        for (int g = 0, i = 0, t = 0; i < n; i++) {
            t = gas[i] - cost[i];
            g += t;
            all += t;
            if (g < 0) {
                pos = i + 1;
                g = 0;
            }
        }
        return all >= 0 ? pos : -1;
    }
};