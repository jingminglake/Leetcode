#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = 0, right = 0;
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                if (i == 0) left = temp.second;
                if (i == size - 1) right = temp.second;
                if (temp.first->left) {
                    q.push(make_pair(temp.first->left, temp.second * 2 + 1));
                }
                if (temp.first->right) {
                    q.push(make_pair(temp.first->right, temp.second * 2 + 2));
                }
            }
            res = max (res, (int)(right - left + 1));
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
    cout <<  s.widthOfBinaryTree(vec[0]);
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    vec.clear();
    return 0;
}
