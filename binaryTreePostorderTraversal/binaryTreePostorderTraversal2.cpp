#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *last_printed = nullptr;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if (!cur->right || cur->right == last_printed) {
                res.push_back(cur->val);
                last_printed = cur;
                s.pop();
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int tree[12] = {1,2,3,4,9999,5,6,9999,9999,9999,9999,7};
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
    vector<int> res = s.postorderTraversal(vec[0]);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    for (TreeNode *t : vec) {
        //cout << t->val << " ";
        delete t;
    }
    vec.clear();
    return 0;
}
