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
        TreeNode* node_k = nullptr;
        dfs(root, node_k, k, parent);
        return bfs(node_k, parent);
    }
    bool dfs(TreeNode* root, TreeNode*& node_k, int k, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return false;
        if (root->val == k) {
            node_k = root;
            return true;
        }
        parent[root->left] = root;
        if (dfs(root->left, node_k, k, parent))
            return true;
        parent[root->right] = root;
        if (dfs(root->right, node_k, k, parent))
            return true;
        return false;
    }
    int bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<TreeNode*> visited;
        visited.insert(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* p = q.front();
                q.pop();
                if (!p->left && !p->right)
                    return p->val;
                if (p->left && !visited.count(p->left)) {
                    q.push(p->left);
                    visited.insert(p->left);
                }
                if (p->right && !visited.count(p->right)) {
                    q.push(p->right);
                    visited.insert(p->right);
                }
                if (parent.count(p) && parent[p] && !visited.count(parent[p])) {
                    q.push(parent[p]);
                    visited.insert(parent[p]);
                }
            }
        }
        return root->val;
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
