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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        getHeight(root, res);
        return res;
    }
    int getHeight(TreeNode* root, bool& res) {
        if (!root)
            return 0;
        int left = getHeight(root->left, res);
        int right = getHeight(root->right, res);
        if (abs(left - right) > 1)
            res = false;
        return max (left, right) + 1;
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
