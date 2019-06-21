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
    Node *last = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        Node dummy(0, nullptr, nullptr);
        last = &dummy;
        inorderVisit(root);
        last->right = dummy.right;
        dummy.right->left = last;
        return dummy.right;
    }
    void inorderVisit(Node* root) {
        if (!root)
            return;
        inorderVisit(root->left);
        last->right = root;
        root->left = last;
        last = root;
        inorderVisit(root->right);
    }
};
