#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        map<int, vector<int> > m;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front(); q.pop();
            m[p.second].push_back(p.first->val);
            if (p.first->left) {
                q.push({p.first->left, p.second - 1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second + 1});
            }
        }
        for (auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[7] = {5,3,6,2,4,9999,7};
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
    for(vector<int>& v : s.verticalOrder(vec[0])) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
