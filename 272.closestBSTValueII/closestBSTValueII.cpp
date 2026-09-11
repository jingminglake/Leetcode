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
    class Compare {
    public:
        bool operator()(const pair<double, int>& p1, const pair<double, int>& p2) {
            return p1.first < p2.first;
        }
    };
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>, vector<pair<double, int> >, Compare > pq;
        helper(root, target, k, pq);
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void helper(TreeNode* root, double target, int k, priority_queue<pair<double, int>, vector<pair<double, int> >, Compare >& pq) {
        if (!root)
            return;
        if (pq.size() < k) {
            pq.emplace(abs(root->val - target), root->val);
        } else if ( abs (root->val - target) < pq.top().first ) {
            pq.emplace(abs(root->val - target), root->val);
            pq.pop();
        }
        helper(root->left, target, k, pq);
        helper(root->right, target, k, pq);
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
