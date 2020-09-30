class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        auto *node = new TreeNode(val);
        if (root == nullptr) {
            return node;
        }
        auto pos = root;
        auto pr = root;
        while (pos != nullptr) {
            pr = pos;
            if (val > pos->val) {
                pos = pos->right;
            } else {
                pos = pos->left;
            }
        }
        if (val > pr->val) {
            pr->right = node;
        } else {
            pr->left = node;
        }
        return root;
    }
};