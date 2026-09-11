#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        deque<int> dq;
        closestKValuesHelper(res, dq, root, target, k);
        while (!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
    void closestKValuesHelper(vector<int>& res, deque<int>& dq, TreeNode* root, double target, int k) {
        if (!root) return;
        closestKValuesHelper(res, dq, root->left, target, k);
        if (dq.size() < k) {
            dq.push_back(root->val);
        } else {
            if (fabs(root->val - target) < fabs(dq.front() - target)) {
                dq.pop_front();
                dq.push_back(root->val);
            }
        }
        closestKValuesHelper(res, dq, root->right, target, k);
    }
};

int main()
{
    Solution s;
    int tree[7] = {10,5,15,9999,9999,6,20};
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
    for (int n : s.closestKValues(vec[0], 7.3, 3))
        cout << n << " ";
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
