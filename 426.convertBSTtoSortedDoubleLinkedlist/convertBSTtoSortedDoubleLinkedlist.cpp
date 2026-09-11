/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        if (!root->left && !root->right) {
            root->left = root->right = root;
            return root;
        }
        Node *right_copy = root->right;
        Node *head_left = treeToDoublyList(root->left);
        Node *head_right = treeToDoublyList(right_copy);
        if (head_left && head_right) {
            Node* last_left = head_left->left;
            Node* last_right = head_right->left;
            head_left->left = last_right;
            last_left->right = root;
            root->left = last_left;
            root->right = head_right;
            head_right->left = root;
            last_right->right = head_left;
            return head_left;
        } else if (head_left) {
            Node* last_left = head_left->left;
            head_left->left = root;
            last_left->right = root;
            root->left = last_left;
            root->right = head_left;
            return head_left;
        } else if (head_right) {
            Node* last_right = head_right->left;
            head_right->left = root;
            last_right->right = root;
            root->left = last_right;
            root->right = head_right;
            return root;
        } else {
            return nullptr;
        }
    }
};
