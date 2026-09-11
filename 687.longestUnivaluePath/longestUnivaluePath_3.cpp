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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        findHelper(root, res);
        return res - 1;
    }
    int findHelper(TreeNode* root, int& res) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            res = max (res, 1);
            return 1;
        }
        int resLeft = findHelper(root->left, res);
        int resRight = findHelper(root->right, res);
        int notPassMax = 1;
        if (root->left && root->left->val == root->val && root->right && root->right->val == root->val) {
            res = max (res, resLeft + resRight + 1);
            notPassMax = max (resLeft, resRight) + 1;
        } else if (root->left && root->left->val == root->val) {
            res = max (res, resLeft + 1);
            notPassMax = resLeft + 1;
        } else if (root->right && root->right->val == root->val) {
            res = max (res, resRight + 1);
            notPassMax = resRight + 1;
        }
        return notPassMax;
    }
};

int main()
{
    Solution s;
    int tree[7] = {5,4,5,1,1,9999,5};
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
    cout << s.longestUnivaluePath(vec[0]) << endl;
  
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
