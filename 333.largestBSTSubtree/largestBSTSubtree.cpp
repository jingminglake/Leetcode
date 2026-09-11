#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class NodeInfo {
public:
    NodeInfo(bool _isBST, long _minV, long _maxV, int _cnt) : isBST(_isBST), minV(_minV), maxV(_maxV), cnt(_cnt) {}
    bool isBST;
    long minV;
    long maxV;
    int cnt;
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        largestBSTSubtreeHelper(root, res);
        return res;
    }
    NodeInfo largestBSTSubtreeHelper(TreeNode* root, int& res) {
        if (!root) return NodeInfo(true, LONG_MAX, LONG_MIN, 0);
        NodeInfo leftRes = largestBSTSubtreeHelper(root->left, res);
        NodeInfo rightRes = largestBSTSubtreeHelper(root->right, res);
        if (leftRes.isBST && rightRes.isBST && root->val > leftRes.maxV && root->val < rightRes.minV) {
            int cnt = leftRes.cnt + rightRes.cnt + 1;
            res = max (res, cnt);
            return NodeInfo(true, min<long>(root->val, leftRes.minV), max<long>(root->val, rightRes.maxV), cnt);
        } else {
            return NodeInfo(false, LONG_MAX, LONG_MIN, 0);
        }
    }
};

int main()
{
    Solution s;
    int tree[7] = {10,5,15,1,8,9999,7};
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
    cout << s.largestBSTSubtree(vec[0]) << endl; 
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
