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
        TreeNode *cur = root;
        while (cur) {
            if (cur->val > p->val && cur->val > q->val)
                cur = cur->left;
            else if (cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else
                return cur;
        }
        return nullptr;
    }
};

int main()
{
    Solution s;
    int tree[11] = {6,2,8,0,4,7,9,9999,9999,3,5};
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
    cout << s.lowestCommonAncestor(vec[0], vec[1], vec[4])->val << endl;
    return 0;
}
