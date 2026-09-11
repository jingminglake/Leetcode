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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = pow(2, h) - 1;
        vector<vector<string> > res(h, vector<string>(w, ""));
        queue<tuple<TreeNode*, int, int> > q;
        q.emplace(root, 0, w - 1);
        int level = 0;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                tuple<TreeNode*, int, int> t = q.front();
                q.pop();
                TreeNode* cur = get<0>(t);
                int left_bound = get<1>(t), right_bound = get<2>(t);
                int pos = (left_bound + right_bound) / 2;
                res[level][pos] = to_string(cur->val);
                if (cur->left) {
                    q.emplace(cur->left, left_bound, pos - 1);
                }
                if (cur->right) {
                    q.emplace(cur->right, pos + 1, right_bound);
                }
            }
            level++;
        }
        return res;
    }
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
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
    for (auto& v : s.printTree(vec[0])) {
        for (string& ss : v) {
            if (!ss.empty())
                cout << "\""<< ss << "\",";
            else
                cout << "\"\",";
        }
        cout << endl;
    }
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
