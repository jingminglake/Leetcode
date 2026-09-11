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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = getHeightForCompleteTree(root->left);
        int rightHeight = getHeightForCompleteTree(root->right);
        if (leftHeight > rightHeight)
            return countNodes(root->left) + (1 << rightHeight);
        else 
            return countNodes(root->right) + (1 << leftHeight);
    }
    int getHeightForCompleteTree(TreeNode* root) {
        int res = 0;
        while (root) {
            res++;
            root = root->left;
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[9] = {5,2,13,1,2,3,4,5,6};
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
    cout << s.countNodes(vec[0]);
    for (TreeNode *t : vec) {
        //cout << t->val << " ";
        delete t;
    }
    cout << endl;
    vec.clear();
    return 0;
}
