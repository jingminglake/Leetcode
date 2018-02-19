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
    if (inorder.size() == 0 || inorder.size() != postorder.size())
      return nullptr;
    unordered_map<int, int> m; // inorder element -> index
    for (int i = 0; i < inorder.size(); i++)
      m[inorder[i]] = i;
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, m);
  }
  TreeNode *buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int istart, int iend, int pstart, int pend, unordered_map<int, int>& m) {
    if (pstart > pend)
      return nullptr;
    TreeNode *root = new TreeNode(postorder[pend]);
    int index = m[postorder[pend]];
    TreeNode *leftT = buildTreeHelper(inorder, postorder, istart, index - 1, pstart, pend - (iend - index) - 1, m);
    TreeNode *rightT = buildTreeHelper(inorder, postorder, index + 1, iend, pend - (iend - index), pend - 1, m);
    root->left = leftT;
    root->right = rightT;
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
