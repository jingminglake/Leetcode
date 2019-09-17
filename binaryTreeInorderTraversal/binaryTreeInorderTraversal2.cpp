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
    Node(TreeNode* _n, int _op) :n(_n), op(_op) {}
    TreeNode *n;
    int op; // 0 -> print, 1 -> visit
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node> s;
        s.push(Node(root, 1));
        while (!s.empty()) {
            Node node = s.top();
            s.pop();
            TreeNode *cur = node.n;
            if (node.op == 1) {
                if (cur->right) s.push(Node(cur->right, 1));
                s.push(Node(cur, 0));
                if (cur->left) s.push(Node(cur->left, 1));
            } else {
                res.push_back(cur->val);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[12] = {1,2,3,4,9999,5,6,9999,9999,9999,9999,7};
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
    vector<int> res = s.inorderTraversal(vec[0]);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    for (TreeNode *t : vec) {
        //cout << t->val << " ";
        delete t;
    }
    vec.clear();
    return 0;
}
