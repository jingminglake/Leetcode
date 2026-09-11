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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }
    int maxPathSumHelper(TreeNode* root, int& res) {
        if (!root) return INT_MIN;
        int leftRes = maxPathSumHelper(root->left, res);
        int rightRes = maxPathSumHelper(root->right, res);
        int maxSide = max(leftRes, rightRes);
        int not_pass_max = (maxSide > 0 ? maxSide : 0) + root->val;
        int pass_max = (leftRes > 0 ? leftRes : 0) + root->val + (rightRes > 0 ? rightRes : 0);
        res = max (res, pass_max);
        res = max (res, not_pass_max);
        return not_pass_max;
    }
};


int main() {
    Solution s;
    int tree[7] = {10,5,15,9999,9999,6,20};
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
    cout << s.maxPathSum(vec[0]) << endl; 
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
