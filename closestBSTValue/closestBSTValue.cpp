#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        double closest = std::numeric_limits<double>::max();
        TreeNode* cur = root;
        while (cur) {
            if (abs(cur->val - target) < closest) {
                closest = abs(cur->val - target);
                res = cur->val;
            }
            cur = cur->val > target ? cur->left : cur->right;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[7] = {10,5,15,9999,9999,6,20};
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
    cout << s.closestValue(vec[0], 7) << endl; 
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
