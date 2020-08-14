/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int root, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(preorder[root]);
        int pos;
        for (pos = left; pos <= right; pos++) {
            if (inorder[pos] == preorder[root]) {
                break;
            }
        }
        node->left = buildTree(preorder, inorder, root + 1, left, pos - 1);
        node->right = buildTree(preorder, inorder, root + pos - left + 1, pos + 1, right);
        return node;
    }
};