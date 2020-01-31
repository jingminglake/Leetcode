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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        pair<bool, int> res = helper(root);
        return res.first;
    }
    pair<bool, int> helper(TreeNode* root) {
        pair<bool, int> res = {true, 0};
        if (!root) return res;
        pair<bool, int> resLeft = helper(root->left);
        pair<bool, int> resRight = helper(root->right);
        res.first = resLeft.first && resRight.first && abs(resLeft.second - resRight.second) <= 1;
        res.second = max (resLeft.second, resRight.second) + 1;
        return res;
    }
};

int main()
{
    Solution s;
    string str = "123#4";
    int size = str.length();
    vector<TreeNode *> vec;
    for (int i = 0; i < size; i++) {
        if (str[i] != '#') {
            vec.push_back(new TreeNode(str[i] - '0'));
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
    cout << s.isBalanced(vec[0]) << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
