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
        if (!root)
            return 0;
        int res = 1;
        helper(root, res);
        return res - 1;
    }
    int helper(TreeNode *root, int& res) {
        if (!root)
            return 0;
        int res_left = helper(root->left, res);
        int res_right = helper(root->right, res);
        res = max (res, res_left);
        res = max (res, res_right);
        int l = 0, r = 0;
        if (root->left && root->val == root->left->val)
            l = res_left;
        if (root->right && root->val == root->right->val)
            r = res_right;
        res = max (res, l + r + 1);
        return max (l, r) + 1;
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
