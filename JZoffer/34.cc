#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    vector<vector<int>> res{};
    vector<int> trace{};
    int target;

  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return res;
        }
        target = sum;
        dfs(root, 0);
        return res;
    }

  private:
    bool isLeaf(TreeNode *node) { return node->left == nullptr && node->right == nullptr; }
    void dfs(TreeNode *node, int count) {
        trace.push_back(node->val);
        count += node->val;
        if (isLeaf(node) && count == target) {
            res.push_back(trace);
            trace.pop_back();
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, count);
        }
        if (node->right != nullptr) {
            dfs(node->right, count);
        }
        trace.pop_back();
    }
};