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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        int max_cnt = 1;
        int cur_cnt = 1;
        int64_t prev = INT64_MIN;
        helper(root, max_cnt, cur_cnt, prev, res);
        return res;
    }
    void helper(TreeNode* root, int& max_cnt, int& cur_cnt, int64_t& prev, vector<int>& res) {
        if (!root)
            return;
        helper(root->left, max_cnt, cur_cnt, prev, res);
        if (prev != INT64_MIN && prev == root->val)
            cur_cnt++;
        else
            cur_cnt = 1;
        if (cur_cnt > max_cnt) {
            max_cnt = cur_cnt;
            res.clear();
            res.push_back(root->val);
        } else if (cur_cnt == max_cnt) {
            res.push_back(root->val);
        }
        prev = root->val;
        helper(root->right, max_cnt, cur_cnt, prev, res);
    }
};

int main()
{
    Solution s;
    int tree[6] = {1,1,2,9999,9999,2};
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
    vector<int> res = s.findMode(vec[0]);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
