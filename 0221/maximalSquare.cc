#include <vector>

using std::vector;

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int>> table(matrix.size(),
                                  vector<int>(matrix[0].size(), 0));
        bool flag = false;
        for (std::size_t i = 0; i < matrix.size() && !flag; i++) {
            for (std::size_t j = 0; j < matrix[0].size() && !flag; j++) {
                if (matrix[i][j] == '1') {
                    flag = true;
                }
            }
        }

        if (!flag) {
            return 0;
        }

        for (std::size_t i = 0; i < matrix.size(); i++) {
            table[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for (std::size_t i = 0; i < matrix[0].size(); i++) {
            table[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        int max = 1;
        for (std::size_t i = 1; i < matrix.size(); i++) {
            for (std::size_t j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    int minLen = std::min(table[i - 1][j], table[i][j - 1]);
                    if (minLen > 0 && matrix[i - minLen][j - minLen] == '1') {
                        max = std::max(max, minLen + 1);
                        table[i][j] = minLen + 1;
                    } else {
                        table[i][j] = std::max(1, minLen);
                    }
                } else {
                    table[i][j] = 0;
                }
            }
        }
        return max * max;
    }
};