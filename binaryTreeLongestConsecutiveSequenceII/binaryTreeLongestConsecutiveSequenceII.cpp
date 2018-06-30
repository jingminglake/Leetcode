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
        helper(root, res);
        return res;
    }
    pair<int, int> helper (TreeNode* root, int& res) {
        if (!root)
            return {0, 0};
        pair<int, int> left_res = helper(root->left, res);
        pair<int, int> right_res = helper(root->right, res);
        int left_res_increase = 0, left_res_decrease = 0;
        int right_res_increase = 0, right_res_decrease = 0;
        if (root->left) {
            int diff = root->val - root->left->val;
            if (diff == 1) {
                left_res_increase = left_res.first;
            } else if (diff == -1) {
                left_res_decrease = left_res.second;
            }
        }
        if (root->right) {
            int diff = root->val - root->right->val;
            if (diff == 1) {
                right_res_increase = right_res.first;
            } else if (diff == -1) {
                right_res_decrease = right_res.second;
            }
        }
        res = max (res, left_res_increase + right_res_decrease + 1);
        res = max (res, left_res_decrease + right_res_increase + 1);
        return { max (left_res_increase, right_res_increase)  + 1, max (left_res_decrease, right_res_decrease) + 1 };
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
