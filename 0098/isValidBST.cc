#include <climits>
#include <cstddef>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    long long num;

  public:
    bool isValidBST(TreeNode *root) {
        num = LLONG_MIN;
        return dfs(root);
    }

    bool dfs(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (!dfs(root->left)) {
            return false;
        }
        if (root->val <= num) {
            return false;
        }
        num = root->val;
        return dfs(root->right);
    }
};