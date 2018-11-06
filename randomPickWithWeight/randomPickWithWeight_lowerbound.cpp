#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class TreeNode {
    public:
        TreeNode(int _key, int _val) : left(nullptr), right(nullptr), key(_key), val(_val){};
        TreeNode *left, *right;
        int key, val;
    };
    Solution(vector<int> w) {
        preSum = w;
        for (int i = 1; i < w.size(); i++)
            preSum[i] += preSum[i - 1];
        root = buildTree(preSum, 0, preSum.size() - 1);
        srand(time(0));
    }
    ~Solution() {
        deleteTree(root);
    }
    
    int pickIndex() {
        int res = -1;
        int len = preSum.size();
        if (len == 0)
            return res;
        int weight = rand() % preSum.back() + 1;
        //cout << "weight: " << weight << endl;
        TreeNode *node = findIndex(root, weight);
        if (node)
            res = node->val;
        return res;
    }
    TreeNode* findIndex(TreeNode *root, int weight) {
        TreeNode *lb = nullptr;
        while (root) {
            if (root->key >= weight) {
                lb = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return lb;
    }
    TreeNode* buildTree(vector<int>& w, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(w[mid], mid);
        //cout << node->key << "->" << node->val << endl;
        node->left = buildTree(w, left, mid - 1);
        node->right = buildTree(w, mid + 1, right);
        return node;
    }
    void deleteTree(TreeNode* root) {
        if (!root)
            return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    TreeNode* root;
    vector<int> preSum;
};

int main() {
    vector<int> w = {1, 3};
    Solution s(w);
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    return 0;
}
