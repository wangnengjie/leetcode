#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>
using std::stack;
using std::vector;

class Solution {
  private:
    inline static const vector<vector<int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int M;
    int N;

  public:
    // out of time
    // int longestIncreasingPath(vector<vector<int>> &matrix) {
    //     if (matrix.empty() || matrix[0].empty()) {
    //         return 0;
    //     }
    //     int M = matrix.size();
    //     int N = matrix[0].size();
    //     auto mem = vector<vector<int>>(M, vector<int>(N));
    //     int res = 0;
    //     for (int i = 0; i < M; i++) {
    //         for (int j = 0; j < N; j++) {
    //             if (mem[i][j] != 0) {
    //                 continue;
    //             }
    //             int max = 1;
    //             auto s1 = stack<vector<int>>();
    //             decltype(s1) s2;
    //             s1.push({i, j, -1});
    //             s2.push({i, j, -1});
    //             while (!s1.empty()) {
    //                 int x = s1.top()[0];
    //                 int y = s1.top()[1];
    //                 if (mem[x][y] != 0) {
    //                     if (s1.size() + mem[x][y] - 1 > max) {
    //                         max = s1.size() + mem[x][y] - 1;
    //                         s2 = decltype(s1)(s1);
    //                     }
    //                     s1.pop();
    //                     continue;
    //                 }
    //                 int next = s1.top()[2] + 1;
    //                 if (next == 4) {
    //                     if (s1.size() > max) {
    //                         max = s1.size();
    //                         s2 = decltype(s1)(s1);
    //                     }
    //                     s1.pop();
    //                     continue;
    //                 }
    //                 int nx = x + direct[next][0];
    //                 int ny = y + direct[next][1];
    //                 s1.top()[2]++;
    //                 if (nx < 0 || nx >= M || ny < 0 || ny >= N || matrix[nx][ny] <= matrix[x][y]) {
    //                     continue;
    //                 }
    //                 s1.push({nx, ny, -1});
    //             }
    //             res = std::max(res, max);

    //             int len = mem[s2.top()[0]][s2.top()[1]] == 0 ? 1 : mem[s2.top()[0]][s2.top()[1]];
    //             while (len <= max && !s2.empty()) {
    //                 mem[s2.top()[0]][s2.top()[1]] = len;
    //                 len++;
    //                 s2.pop();
    //             }
    //         }
    //     }
    //     return res;
    // }

    auto longestIncreasingPath(vector<vector<int>> &matrix) -> int {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        M = matrix.size();
        N = matrix[0].size();
        auto mem = vector<vector<int>>(M, vector<int>(N));
        int res = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                res = std::max(res, dfs(i, j, matrix, mem));
            }
        }
        return res;
    }

    auto dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &mem) -> int {
        if (mem[x][y] != 0) {
            return mem[x][y];
        }
        mem[x][y] = 1;
        for (const auto &d : direct) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || matrix[nx][ny] <= matrix[x][y]) {
                continue;
            }
            mem[x][y] = std::max(mem[x][y], dfs(nx, ny, matrix, mem) + 1);
        }
        return mem[x][y];
    }
};