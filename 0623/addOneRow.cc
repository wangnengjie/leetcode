class Solution {
  public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        auto tmp = vector<TreeNode *>();
        auto nodeQueue = queue<TreeNode *>();
        nodeQueue.push(root);
        nodeQueue.push(nullptr);
        while (d > 2) {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            if (node == nullptr) {
                d--;
                if (!nodeQueue.empty()) {
                    nodeQueue.push(nullptr);
                }
            } else {
                if (node->left)
                    nodeQueue.push(node->left);
                if (node->right)
                    nodeQueue.push(node->right);
            }
        }
        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            if (node == nullptr) {
                continue;
            }
            auto lnode = new TreeNode(v);
            auto rnode = new TreeNode(v);
            lnode->left = node->left;
            rnode->right = node->right;
            node->left = lnode;
            node->right = rnode;
        }
        return root;
    }
};