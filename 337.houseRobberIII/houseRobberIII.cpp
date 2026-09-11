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
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max (res.first, res.second);
    }
    pair<int, int> helper(TreeNode* root) {
        pair<int, int> res = {0, 0}; // first -> not choose, second -> choose
        if (!root)
            return res;
        pair<int, int> res_left = helper(root->left);
        pair<int, int> res_right = helper(root->right);
        res.first = max (res_left.first, res_left.second) + max (res_right.first, res_right.second);
        res.second = res_left.first + res_right.first + root->val;
        return res;
    }
};

int main()
{
    int tree[7] = {3,2,3,9999,3,9999,1};
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
    Solution s;
    cout << s.rob(vec[0]) << endl;
    for (TreeNode * tn : vec) {
        delete tn;
    }
    vec.clear();
    return 0;
}
