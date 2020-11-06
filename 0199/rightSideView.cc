class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> tq;
        tq.push(root);
        tq.push(nullptr);
        while (!tq.empty()) {
            auto node = tq.front();
            tq.pop();
            if (node == nullptr) {
                if (!tq.empty()) {
                    tq.push(nullptr);
                }
                continue;
            }
            if (!tq.empty() && tq.front() == nullptr) {
                res.push_back(node->val);
            }
            if (node->left != nullptr)
                tq.push(node->left);
            if (node->right != nullptr)
                tq.push(node->right);
        }
        return res;
    }
};