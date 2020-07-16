#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        auto trace = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            if (trace[i] == 0) {
                trace[i] = 1;
                auto q = queue<int>();
                q.push(i);
                while (!q.empty()) {
                    auto node = q.front();
                    int next = trace[node] == 1 ? -1 : 1;
                    for (auto &nn : graph[node]) {
                        if (trace[nn] == 0) {
                            trace[nn] = next;
                            q.push(nn);
                        } else if (trace[nn] != next) {
                            return false;
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};