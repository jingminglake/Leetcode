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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

int main()
{
    Solution s;
    int tree[8] = {1,-2,-3,1,3,-2,9999,-1};
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

    vector<TreeNode *> vec2;
    for (int i = 0; i < size; i++) {
        if (tree[i] != 9999) {
            vec2.push_back(new TreeNode(tree[i]));
        } else {
            vec2.push_back(NULL);
        }
    }
    for (int i = 0; i < size/2; i++) {
        if(!vec2[i])
            continue;
        if (i*2 + 1 < size)
            vec2[i]->left = vec2[i*2 + 1];
        if (i*2 + 2 < size)
            vec2[i]->right = vec2[i*2 + 2];
    }
  
    cout << s.isSameTree(vec[0], vec2[0]) << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    for (TreeNode *t : vec2) {
        delete t;
    }
    vec.clear();
    return 0;
}
