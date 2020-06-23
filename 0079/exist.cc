#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> direct = vector<vector<int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool exist(vector<vector<char>> &board, string word) {
        if (board.size() * board[0].size() < word.size()) {
            return false;
        }
        auto charMap = unordered_map<char, vector<pair<int, int>>>();
        auto traceBoard = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[i].size(); j++) {
                charMap[board[i][j]].push_back({i, j});
            }
        }
        for (auto &pair : charMap[word.at(0)]) {
            traceBoard[pair.first][pair.second] = true;
            if (search(pair.first, pair.second, 1, board, word, traceBoard)) {
                return true;
            }
            traceBoard[pair.first][pair.second] = false;
        }
        return false;
    }

    bool search(size_t i, size_t j, size_t next, vector<vector<char>> &board, const string &word,
                vector<vector<bool>> &trace) {
        if (next == word.size()) {
            return true;
        }
        auto c = word.at(next);
        size_t ni = 0;
        size_t nj = 0;
        for (auto &d : direct) {
            ni = i + d[0]; // -1 -> MAX_LONG
            nj = j + d[1];
            if (ni >= board.size() || nj >= board[0].size() || board[ni][nj] != c || trace[ni][nj] == true) {
                continue;
            }
            trace[ni][nj] = true;
            if (search(ni, nj, next + 1, board, word, trace)) {
                return true;
            }
            trace[ni][nj] = false;
        }
        return false;
    }
};