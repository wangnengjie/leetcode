#include <vector>
#include <queue>
#include <unordered_set>

using std::pair;
using std::queue;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    using gridIndex = pair<int, int>;
    using queueNode = pair<gridIndex, int>;
    struct pairHash
    {
        inline int operator()(const gridIndex &v) const
        {
            return v.first * 31 + v.second;
        }
    };
    unordered_set<gridIndex, pairHash> hasGetSet = unordered_set<gridIndex, pairHash>();
    queue<queueNode> bfsQueue = queue<queueNode>();

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return grid[0][0] == 0 ? 1 : -1;
        hasGetSet.insert(gridIndex(0, 0));
        bfsQueue.push(queueNode(gridIndex(0, 0), 1));
        while (!bfsQueue.empty())
        {
            auto node = bfsQueue.front();
            bfsQueue.pop();
            const int &row = node.first.first, &col = node.first.second;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (row + j == n - 1 && col + i == n - 1)
                        return node.second + 1;
                    if (canGo(row + j, col + i, n, grid))
                        update(gridIndex(row + j, col + i), node.second + 1);
                }
            }
        }
        return -1;
    }

    void update(gridIndex &&t, int &&step)
    {
        hasGetSet.insert(t);
        bfsQueue.push(queueNode(t, step));
    }

    bool canGo(const int &row, const int &col, const int &size, const vector<vector<int>> &grid)
    {
        if (row < 0 || col < 0 || row >= size || col >= size)
            return false;
        if (hasGetSet.find(gridIndex(row, col)) != hasGetSet.end())
            return false;
        if (grid[row][col] == 1)
            return false;
        return true;
    }
};