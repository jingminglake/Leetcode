#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> res = diameterOfBinaryTreeHelper(root);
        return res[1];
    }
    
    vector<int> diameterOfBinaryTreeHelper(TreeNode* root) {
        if (!root) return {0, 0};
        vector<int> resLeft = diameterOfBinaryTreeHelper(root->left);
        vector<int> resRight = diameterOfBinaryTreeHelper(root->right);
        int passLen = resLeft[0] + resRight[0];
        return {max(resLeft[0], resRight[0]) + 1, max(passLen, max(resLeft[1], resRight[1]))}; // first: max end with root, second: local max
    }
};

int main()
{
    Solution s;
    int tree[4] = {1,2,3,4};
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
    cout << s.diameterOfBinaryTree(vec[0]) << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
