#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    string tree2str(TreeNode *t) {
        string res;
        if (!t) return res; 
        if (!t->left && !t->right) return to_string(t->val);
        res += to_string(t->val) + "(" + tree2str(t->left) + ")";
        if (t->right) res += "(" + tree2str(t->right) + ")";
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
    cout << s.tree2str(vec[0]) << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
