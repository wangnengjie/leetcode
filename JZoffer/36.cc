
class Node {
  public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
  private:
    Node *minNode = nullptr;
    Node *prev = nullptr;

  public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        build(root);
        minNode->left = prev;
        prev->right = minNode;
        return minNode;
    }

    void build(Node *node) {
        if (node == nullptr) {
            return;
        }
        build(node->left);
        if (minNode == nullptr) {
            minNode = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        build(node->right);
    }
};