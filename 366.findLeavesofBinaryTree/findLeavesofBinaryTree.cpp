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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > res;
        findLeavesHelper(root, res);
        return res;
    }
    int findLeavesHelper(TreeNode* root, vector<vector<int> >& res) {
        if (!root) return 0;
        int h = max (findLeavesHelper(root->left, res), findLeavesHelper(root->right, res)) + 1;
        if (h - 1 == res.size()) {
            res.push_back(vector<int>());
        }
        res[h - 1].push_back(root->val);
        return h;
    }
};

int main()
{
    Solution s;
    int tree[7] = {5,3,6,2,4,9999,7};
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
    vector<vector<int> > res = s.findLeaves(vec[0]);
    for (vector<int>& v : res) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
