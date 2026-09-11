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
        int res = 0;
        if (!root)
            return res;
        dfs(root, res, 1, INT64_MIN);
        return res;
    }
    void dfs(TreeNode* root, int& res, int path, int64_t prev) {
        if (!root)
            return;
        if (root->val == prev + 1) {
            path++;
        } else {
            path = 1;
        }
        res = max (res, path);
        dfs (root->left, res, path, root->val);
        dfs (root->right, res, path, root->val);
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
