#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) return {nullptr, nullptr};
        if (V >= root->val) {
            vector<TreeNode*> rightRes = splitBST(root->right, V);
            root->right = rightRes[0];
            return {root, rightRes[1]};
        } else {
            vector<TreeNode*> leftRes = splitBST(root->left, V);
            root->left = leftRes[1];
            return {leftRes[0], root};
        }
    }
};

void preorder(TreeNode *root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Solution s;
    int tree[7] = {4,2,6,1,3,5,7};
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
    vector<TreeNode*> res = s.splitBST(vec[0], 2);
    preorder(res[0]);
    cout << endl;
    preorder(res[1]);
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
