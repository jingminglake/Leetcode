#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || inorder.size() != postorder.size()) return nullptr;
        int size = inorder.size();
        unordered_map<int, int> m;
        for (int i = 0; i < size; i++) {
            m[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0, size - 1, 0, size - 1, m);
    }
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int i_start, int i_end, int p_start, int p_end, unordered_map<int, int>& m) {
        if (i_start > i_end || p_start > p_end) return nullptr;
        TreeNode *root = new TreeNode(postorder[p_end]);
        int leftSize = m[postorder[p_end]] - i_start;
        root->left = buildTreeHelper(inorder, postorder, i_start, m[postorder[p_end]] - 1, p_start, p_start + leftSize - 1, m);
        root->right = buildTreeHelper(inorder, postorder, m[postorder[p_end]] + 1, i_end,  p_start + leftSize, p_end - 1, m);
        return root;
    }
    void preorder(TreeNode *root) {
        if (!root)
            return;
        TreeNode *leftChild = root->left;
        TreeNode *rightChild = root->right;
        cout << root->val << " ";
        delete root;
        preorder(leftChild);
        preorder(rightChild);
    }
};

int main()
{
    Solution s;
    int a[4] = {4,2,1,3};
    int b[4] = {4,2,3,1};
    vector<int> vec1(a,a+4);
    vector<int> vec2(b,b+4);
    TreeNode* res = s.buildTree(vec1, vec2);
    s.preorder(res);
    cout << endl;
    return 0;
}
