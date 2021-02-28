/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        int ld = depth(root->left);
        int rd = depth(root->right);
        if (ld == rd) {
            return root;
        }
        if (ld < rd) {
            return subtreeWithAllDeepest(root->right);
        }
        return subtreeWithAllDeepest(root->left);
    }

    int depth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return max(depth(node->left), depth(node->right)) + 1;
    }
};