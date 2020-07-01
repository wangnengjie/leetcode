#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &A, vector<int> &B) {
        auto table = vector<int>(B.size() + 1);
        int max = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            for (int j = 0; j < B.size(); j++) {
                table[j] = A[i] == B[j] ? table[j + 1] + 1 : 0;
                max = std::max(table[j], max);
            }
        }
        return max;
    }
};