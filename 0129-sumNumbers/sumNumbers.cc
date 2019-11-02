#include <memory>

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
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        int result = 0;
        dfs(root, 0, result);
        return result;
    }

    void dfs(TreeNode *root, int count, int &result)
    {
        if (!root->left && !root->right)
        {
            result += count + root->val;
            return;
        }
        count += root->val;
        count *= 10;
        if (root->left)
            dfs(root->left, count, result);
        if (root->right)
            dfs(root->right, count, result);
    }
};