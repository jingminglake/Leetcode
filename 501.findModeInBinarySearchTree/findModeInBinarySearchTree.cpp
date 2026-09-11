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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int64_t prev = INT64_MIN;
        int modeMax = 0;
        int curNumber = 0;
        findModeHelper(root, res, prev, modeMax, curNumber);
        return res;
    }
    void findModeHelper(TreeNode* root, vector<int>& res, int64_t& prev, int& modeMax, int& curNumber) {
        if (!root) return;
        findModeHelper(root->left, res, prev, modeMax, curNumber);
        if (prev == root->val) {
            curNumber++;
        } else {
            curNumber = 1;
            prev = root->val;
        }
        if (curNumber > modeMax) {
            res.clear();
            modeMax = curNumber;
            res.push_back(root->val);
        } else if (curNumber == modeMax){
            res.push_back(root->val);
        }
        findModeHelper(root->right, res, prev, modeMax, curNumber);
    }
};

int main()
{
    Solution s;
    int tree[6] = {1,1,2,9999,9999,2};
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
    vector<int> res = s.findMode(vec[0]);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
