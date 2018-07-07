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
        if (!root)
            return true;
        unordered_map<TreeNode*, int> m;
        getHeight(root, m);
        return isBalancedHelper(root, m);
    }
    bool isBalancedHelper(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (!root)
            return true;
        return (abs(m[root->left] - m[root->right]) <= 1) && isBalancedHelper(root->left, m) && isBalancedHelper(root->right, m);
    }
    int getHeight(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (!root)
            return m[root] = 0;
        return m[root] = max(getHeight(root->left, m), getHeight(root->right, m)) + 1;
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
