#include <queue>

using std::queue;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         auto bfsQueue = queue<Node *>();
//         bfsQueue.push(root);
//         bfsQueue.push(nullptr);
//         while (bfsQueue.front() != nullptr)
//         {
//             auto cur = bfsQueue.front();
//             bfsQueue.pop();
//             auto next = bfsQueue.front();
//             cur->next = next;
//             bfsQueue.push(cur->left);
//             bfsQueue.push(cur->right);
//             if (next == nullptr)
//             {
//                 bfsQueue.pop();
//                 bfsQueue.push(nullptr);
//             }
//         }
//         return root;
//     }
// };

// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         if (!root)
//             return root;
//         Node *left = root->left;
//         Node *right = root->right;
//         while (left)
//         {
//             left->next = right;
//             left = left->right;
//             right = right->left;
//         }
//         connect(root->left);
//         connect(root->right);
//         return root;
//     }
// };