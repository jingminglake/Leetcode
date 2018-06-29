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
        int cur_cnt = 0;
        int64_t prev = INT64_MAX;
        inorder(root, prev, res, max_cnt, cur_cnt);
        return res;
    }
    void inorder(TreeNode* root, int64_t& prev, vector<int>& res, int& max_cnt, int& cur_cnt) {
        if (!root)
            return;
        inorder(root->left, prev, res, max_cnt, cur_cnt);
        if (prev == INT64_MAX || root->val == prev) {
            cur_cnt++;
        } else {
            cur_cnt = 1;
        }
        if (cur_cnt > max_cnt) {
            res.clear();
            res.push_back(root->val);
            max_cnt = cur_cnt;
        } else if (cur_cnt == max_cnt) {
            res.push_back(root->val);
        }
        prev = root->val;
        inorder(root->right, prev, res, max_cnt, cur_cnt);
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
