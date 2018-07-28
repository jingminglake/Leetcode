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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);
        if (leftRes && rightRes)
            return root;
        else if (!leftRes)
            return rightRes;
        else if (!rightRes)
            return leftRes;
        else
            return nullptr;
    }
};

int main()
{
    Solution s;
    int tree[11] = {3,5,1,6,2,0,8,9999,9999,7,4};
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
    cout << s.lowestCommonAncestor(vec[0], vec[1], vec[9])->val;
    cout << endl;
    for (TreeNode *t : vec) {
        //cout << t->val << " ";
        delete t;
    }
    vec.clear();
    return 0;
}
