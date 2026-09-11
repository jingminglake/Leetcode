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

class Solution{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if (!root) return res;
        unordered_map<string, int> m;
        findDuplicateSubtreesHelper(root, m, res);
        return res;
    }
    string findDuplicateSubtreesHelper(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!root) return "#";
        string leftRes = findDuplicateSubtreesHelper(root->left, m, res);
        string rightRes = findDuplicateSubtreesHelper(root->right, m, res);
        string treeStr = to_string(root->val) + leftRes + rightRes;
        if (m[treeStr] == 1) res.push_back(root);
        m[treeStr]++;
        return treeStr;
    }
    void preorder(TreeNode *root) {
        if (!root)
            return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main()
{
    int tree[12] = {1,2,3,4,9999,2,4,9999,9999,9999,9999,4};
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
    Solution s;
    vector<TreeNode*> res = s.findDuplicateSubtrees(vec[0]);
    for (TreeNode* t : res) {
        s.preorder(t);
        cout << endl;
    }
    for (TreeNode * tn : vec) {
        delete tn;
    }
    vec.clear();
    return 0;
}
