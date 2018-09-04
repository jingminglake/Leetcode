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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        dfs(root, res, "");
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string path) {
        if (!root->left && !root->right) {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if (root->left)
            dfs(root->left, res, path);
        if (root->right)
            dfs(root->right, res, path);
    }
};

int main()
{
    Solution s;
    int tree[5] = {1,2,3,9999,5};
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
    vector<string> paths = s.binaryTreePaths(vec[0]);
    for (string str : paths) {
        cout << str << endl;
    }
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
