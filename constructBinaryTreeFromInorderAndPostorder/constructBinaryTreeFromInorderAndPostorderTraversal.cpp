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
    int iSize = inorder.size();
    int pSize = postorder.size();
    if (!iSize || !pSize || iSize != pSize)
      return NULL;
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
      m[inorder[i]] = i;
    return generate(inorder, 0 ,iSize - 1, postorder, 0, pSize - 1,  m);
  }
  TreeNode* generate(vector<int>& inorder, int iStart, int iEnd, vector<int>& postorder, int pStart, int pEnd, unordered_map<int, int>& m) {
    if (iStart > iEnd || pStart > pEnd)
      return NULL;
    TreeNode *root = new TreeNode(postorder[pEnd]);
    int index = m[postorder[pEnd]];
    TreeNode *leftChild = generate(inorder, iStart ,index - 1, postorder, pStart, pStart + index - 1 - iStart,  m);
    TreeNode *rightChild = generate(inorder, index + 1, iEnd, postorder, pStart + index - iStart, pEnd - 1,  m);
    root->left = leftChild;
    root->right = rightChild;
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
