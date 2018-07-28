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
    pair<int, int> helper(TreeNode* root, int& res) {
        if (!root)
            return {0, 0};
        pair<int, int> local_res_left = helper(root->left, res);
        pair<int, int> local_res_right = helper(root->right, res);
        pair<int, int> local_res = {1, 1}; // first : increase, second : decrease
        if (root->left) {
            int diff = root->val - root->left->val;
            if (diff == 1) {
                local_res.first = local_res_left.first + 1;
            } else if (diff == -1) {
                local_res.second = local_res_left.second + 1;
            }
        }
        if (root->right) {
            int diff = root->val - root->right->val;
            if (diff == 1) {
                local_res.first = max (local_res.first, local_res_right.first + 1);
            } else if (diff == -1){
                local_res.second = max (local_res.second, local_res_right.second + 1);
            }
        }
        res = max (res, local_res.first + local_res.second - 1);
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
