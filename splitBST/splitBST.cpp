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
        vector<TreeNode*> res(2, nullptr);
        if (!root)
            return res;
        if (root->val > V) {
            res[1] = root;
            vector<TreeNode*> left_res = splitBST(root->left, V);
            res[1]->left = left_res[1];
            res[0] = left_res[0];
        } else {
            res[0] = root;
            vector<TreeNode*> right_res = splitBST(root->right, V);
            res[0]->right = right_res[0];
            res[1] = right_res[1];
        }
        return res;
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
