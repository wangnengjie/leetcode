#include <vector>
using std::vector;

class Solution {
  public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        for (int i = 1; i < arr.size(); i++) {
            arr[i] ^= arr[i - 1];
        }
        auto res = vector<int>(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                res[i] = arr[queries[i][1]];
            } else {
                res[i] = arr[queries[i][0] - 1] ^ arr[queries[i][1]];
            }
        }
        return res;
    }
};