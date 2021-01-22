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
    vector<int> levelOrder(TreeNode *root) {
        auto res = vector<int>();
        if (root == nullptr) {
            return res;
        }
        auto q = queue<TreeNode *>();
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return res;
    }
};