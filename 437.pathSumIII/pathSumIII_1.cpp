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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int path = 0;
        int res = 0;
        dfs(root, sum, path, res);
        return res + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    void dfs(TreeNode* root, int sum, int& path, int& res) {
        if (!root) return;
        path += root->val;
        if (path == sum) res++;
        dfs(root->left, sum, path, res);
        dfs(root->right, sum, path, res);
        path -= root->val;
    }
};

int main()
{
    Solution s;
    int tree[8] = {1,-2,-3,1,3,-2,9999,-1};
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
    cout << s.pathSum(vec[0], -2) << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
