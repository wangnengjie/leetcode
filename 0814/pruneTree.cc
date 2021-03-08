class Solution {
  public:
    TreeNode *pruneTree(TreeNode *root) {
        int count = dfs(root);
        return count == 0 ? nullptr : root;
    }

    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int countLeft = dfs(node->left);
        int countRight = dfs(node->right);
        if (countLeft == 0) {
            node->left = nullptr;
        }
        if (countRight == 0) {
            node->right = nullptr;
        }
        return countLeft + countRight + (node->val == 1 ? 1 : 0);
    }
};