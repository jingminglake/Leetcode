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
    int helper(TreeNode* root, int& res) {
        if (!root)
            return 0;
        int local_res_left = helper(root->left, res);
        int local_res_right = helper(root->right, res);
        int local_res = 1;
        if (root->left && root->left->val == root->val) {
            local_res = max (local_res, local_res_left + 1);
        }
        if (root->right && root->right->val == root->val) {
            local_res = max (local_res, local_res_right + 1);
        }
        res = max (res, local_res);
        if (root->left && root->right && root->left->val == root->val && root->right->val == root->left->val)
            res = max (res, local_res_left + local_res_right + 1);
        return local_res;
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
