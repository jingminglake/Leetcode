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
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        int res = 1;
        longestConsecutiveHelper(root, res);
        return res;
    }
    int longestConsecutiveHelper(TreeNode* root, int& res) {
        if (!root)
            return 0;
        int local_res = 1;
        int res_left = longestConsecutiveHelper(root->left, res);
        int res_right = longestConsecutiveHelper(root->right, res);
        if (root->left && root->val == root->left->val - 1) {
            local_res = max (local_res, res_left + 1);
        }
        if (root->right && root->val == root->right->val - 1) {
            local_res = max (local_res, res_right + 1);
        }
        res = max (res, local_res);
        return local_res;
    }
};

int main()
{
    Solution s;
    int tree[7] = {1,2,2,9999,9999,3,7};
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
    cout << s.longestConsecutive(vec[0]);
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
