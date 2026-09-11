#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode* > q;
        q.push(root);
        bool zigzagFlag = false;
        while (!q.empty()) {
            vector<int> vec;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = q.front(); q.pop();
                vec.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            if (zigzagFlag) reverse(vec.begin(), vec.end());
            zigzagFlag = !zigzagFlag;
            res.push_back(vec);
        }
        return res;
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
    vector<vector<int> > res = s.zigzagLevelOrder(vec[0]);
    for (vector<int> &v : res) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    for (TreeNode *t : vec) {
        //cout << t->val << " ";
        delete t;
    }
    vec.clear();
    return 0;
}
