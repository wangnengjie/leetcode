#include <vector>
#include <queue>

using std::queue;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        auto re = vector<vector<int>>();
        auto bfsQueue = queue<TreeNode *>();
        bfsQueue.push(root);
        bfsQueue.push(NULL);
        for (bool flag = true; bfsQueue.front(); flag = !flag)
        {
            auto t = vector<int>();
            while (bfsQueue.front())
            {
                TreeNode *top = bfsQueue.front();
                t.push_back(top->val);
                if (top->left)
                    bfsQueue.push(top->left);
                if (top->right)
                    bfsQueue.push(top->right);
                bfsQueue.pop();
            }
            bfsQueue.pop();
            bfsQueue.push(NULL);
            if (!flag)
                std::reverse(t.begin(), t.end());
            re.push_back(t);
        }
        return re;
    }
};