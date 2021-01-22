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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        auto q = queue<TreeNode *>();
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            auto n1 = q.front();
            q.pop();
            auto n2 = q.front();
            q.pop();
            if (n1 == NULL && n2 == NULL) {
                continue;
            }
            if ((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL) || (n1->val != n2->val)) {
                return false;
            }
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);
        }
        return true;
    }
};