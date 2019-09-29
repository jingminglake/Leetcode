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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (root->left || root->right) res.push_back(root->val);
        vector<int> leftBound = findLeftBound(root);
        vector<int> leaf;
        findLeaf(root, leaf);
        vector<int> rightBound = findRightBound(root);
        res.insert(res.end(), leftBound.begin(), leftBound.end());
        res.insert(res.end(), leaf.begin(), leaf.end());
        res.insert(res.end(), rightBound.rbegin(), rightBound.rend());
        return res;
    }
    vector<int> findLeftBound(TreeNode* root) {
        vector<int> leftBound;
        TreeNode* cur = root->left;
        while (cur) {
            if (cur->left || cur->right)
                leftBound.push_back(cur->val);
            if (cur->left)
                cur = cur->left;
            else if (cur->right && (cur->right->left || cur->right->right))
                cur = cur->right;
            else
                cur = nullptr;
        }
        return leftBound;
    }
    void findLeaf(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (!root->left && !root->right) res.push_back(root->val);
        findLeaf(root->left, res);
        findLeaf(root->right, res);
    }
    vector<int> findRightBound(TreeNode* root) {
        vector<int> rightBound;
        TreeNode *cur = root->right;
        while (cur) {
            if (cur->left || cur->right)
                rightBound.push_back(cur->val);
            if (cur->right)
                cur = cur->right;
            else if (cur->left && (cur->left->left || cur->left->right))
                cur = cur->left;
            else
                cur = nullptr;
        }
        return rightBound;
    }
};

int main()
{
    Solution s;
    int tree[7] = {3,9,20,9999,9999,15,7};
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
    for (int i : s.boundaryOfBinaryTree(vec[0]))
        cout << i << " ";
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
