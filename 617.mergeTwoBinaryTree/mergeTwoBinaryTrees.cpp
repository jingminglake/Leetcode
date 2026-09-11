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

class Solution{
public:
    TreeNode* mergeTrees(TreeNode *t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        int val1 = t1 ? t1->val : 0;
        int val2 = t2 ? t2->val : 0;
        TreeNode *root = new TreeNode(val1 + val2);
        root->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
        root->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
        return root;
    }
};

int main()
{
    Solution s;
    int tree[4] = {1,3,2,5};
    int tree2[7] = {2,1,3,9999,4,9999,7};
    int size = sizeof(tree)/sizeof(tree[0]);
    int size2 = sizeof(tree2)/sizeof(tree2[0]);
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
    for (int i = 0; i < size2; i++) {
        if (tree2[i] != 9999) {
            vec2.push_back(new TreeNode(tree2[i]));
        } else {
            vec2.push_back(NULL);
        }
    }
    for (int i = 0; i < size2/2; i++) {
        if(!vec2[i])
            continue;
        if (i*2 + 1 < size2)
            vec2[i]->left = vec2[i*2 + 1];
        if (i*2 + 2 < size2)
            vec2[i]->right = vec2[i*2 + 2];
    }
  
    TreeNode* temp = s.mergeTrees(vec[0], vec2[0]);
    queue<TreeNode *> q;
    q.push(temp);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp) {
            cout << temp->val << " ";
            if (temp->left || temp->right) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        else
            cout << "# ";
    }
    cout << endl;
    for (TreeNode *t : vec) {
        delete t;
    }
    for (TreeNode *t : vec2) {
        delete t;
    }
    vec.clear();
    return 0;
}
