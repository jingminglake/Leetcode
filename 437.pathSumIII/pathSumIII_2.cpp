#include <iostream>
#include <vector>
#include <unordered_map>
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
        int res = 0;
        if (!root) return res;
        unordered_map<int, int> preSum_m;
        preSum_m[0] = 1;
        int path = 0;
        dfs(root, sum, preSum_m, path, res);
        return res;
    }
    void dfs(TreeNode* root, int sum, unordered_map<int, int>& preSum_m, int& path, int& res) {
        if (!root) return;
        path += root->val;
        res += preSum_m[path - sum];
        preSum_m[path]++;
        dfs(root->left, sum, preSum_m, path, res);
        dfs(root->right, sum, preSum_m, path, res);
        preSum_m[path]--;
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
