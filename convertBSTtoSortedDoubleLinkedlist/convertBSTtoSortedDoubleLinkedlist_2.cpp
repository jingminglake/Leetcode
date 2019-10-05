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
        if (!root) return root;
        Node dummy;
        Node* last = &dummy;
        treeToDoublyistHelper(root, last);
        dummy.right->left = last;
        last->right = dummy.right;
        return dummy.right;
    }
    void treeToDoublyistHelper(Node* root, Node*& last) {
        if (!root) return;
        treeToDoublyistHelper(root->left, last);
        last->right = root;
        root->left = last;
        last = last->right;
        treeToDoublyistHelper(root->right, last);
    }
};
