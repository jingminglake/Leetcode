#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode *t_k = findK(root, k, parent);
        return bfs(t_k, parent);
    }
    TreeNode *findK(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root) return nullptr;
        if (root->val == k) return root;
        if (root->left) parent[root->left] = root;
        TreeNode *t_left = findK(root->left, k, parent);
        if (t_left) return t_left;
        if (root->right) parent[root->right] = root;
        TreeNode *t_right = findK(root->right, k, parent);
        if (t_right) return t_right;
        return nullptr;
    }
    int bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(root);
        visited.insert(root);
        while (!q.empty()) {
            TreeNode* t = q.front(); q.pop();
            if (!t->left && !t->right) return t->val;
            if (t->left && !visited.count(t->left)) {
                visited.insert(t->left);
                q.push(t->left);
            }
            if (t->right && !visited.count(t->right)) {
                visited.insert(t->right);
                q.push(t->right);
            }
            if (parent.count(t) && !visited.count(parent[t])) {
                visited.insert(parent[t]);
                q.push(parent[t]);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    string str = "123#4####5";
    int size = str.length();
    vector<TreeNode *> vec;
    for (int i = 0; i < size; i++) {
        if (str[i] != '#') {
            vec.push_back(new TreeNode(str[i] - '0'));
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
    cout << s.findClosestLeaf(vec[0], 2) << endl;
    return 0;
}
