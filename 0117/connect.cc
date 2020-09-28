class Solution {
  public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }
        auto q = queue<Node *>();
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                if (!q.empty()) {
                    q.push(nullptr);
                }
                continue;
            }
            node->next = q.front();
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return root;
    }
};