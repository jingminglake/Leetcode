#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    Node(TreeNode* _node, int _op) : node(_node), op(_op) {};
    TreeNode *node;
    int op; // 0 -> print, 1 -> visit
};
class Solution {
public:
    class Node {
    public:
        Node(TreeNode* n, int _op) : node(n), op(_op) {}
        TreeNode* node;
        int op; // 0 -> print, 1 -> visit
    };
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node> s;
        s.push(Node(root, 1));
        while (!s.empty()) {
            Node n = s.top(); s.pop();
            if (n.op == 1) {
                if (n.node->right) s.push(Node(n.node->right, 1));
                if (n.node->left) s.push(Node(n.node->left, 1));
                s.push(Node(n.node, 0));
            } else {
                res.push_back(n.node->val);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[6] = {1, 9999, 2, 9999, 9999, 3};
    int size = sizeof(tree)/sizeof(tree[0]);
    vector<TreeNode *> vec;
    for (int i = 0; i < size; i++) {
        if (tree[i] != 9999) {
            vec.push_back(new TreeNode(tree[i]));
        } else {
            vec.push_back(NULL);
        }
    }
    for (int i = 0; i < size/2; i++) {
        if(!vec[i])
            continue;
        if (i*2 + 1 < size)
            vec[i]->left = vec[i*2 + 1];
        if (i*2 + 2 < size)
            vec[i]->right = vec[i*2 + 2];
    }
    vector<int> res = s.preorderTraversal(vec[0]);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
