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
    Node(TreeNode* _t, int _op) : treeNode(_t), op(_op) {}
    TreeNode *treeNode;
    int op;
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root) s.push(Node(root, 1));
    }
    
    /** @return the next smallest number */
    int next() {
        int res = -1;
        if (hasNext()) {
            res = s.top().treeNode->val; s.pop();
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) return false;
        while (s.top().op == 1) {
            TreeNode *cur = s.top().treeNode; s.pop();
            if (cur->right) s.push(Node(cur->right, 1));
            s.push(Node(cur, 0));
            if (cur->left) s.push(Node(cur->left, 1));
        }
        return true;
    }
    stack<Node> s;
};


int main()
{
    int tree[7] = {5,3,6,2,4,9999,7};
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
    BSTIterator i = BSTIterator(vec[0]);
    while (i.hasNext())
        cout << i.next() << " ";
    cout << endl;
    vec.clear();
    return 0;
}
