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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pSize = preorder.size();
    int iSize = inorder.size();
    if (!iSize || !pSize || iSize != pSize)
      return NULL;
    unordered_map<int, int> m(iSize);
    for (int i = 0; i < iSize; i++)
      m[inorder[i]] = i;
    return generate(preorder, 0 ,pSize - 1, inorder, 0, iSize - 1,  m);
  }
  TreeNode* generate(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& m) {
    if (iStart > iEnd || pStart > pEnd)
      return NULL;
    TreeNode *root = new TreeNode(preorder[pStart]);
    int index = m[preorder[pStart]];
    TreeNode *leftChild = generate(preorder, pStart + 1, pStart + index - iStart, inorder, iStart, iStart + index - 1,  m);
    TreeNode *rightChild = generate(preorder, pStart + index - iStart + 1, pEnd, inorder, index + 1, iEnd, m);
    root->left = leftChild;
    root->right = rightChild;
    return root;
  }
  void postorder(TreeNode *root) {
    if (!root)
      return;
    TreeNode *leftChild = root->left;
    TreeNode *rightChild = root->right;
    postorder(leftChild);
    postorder(rightChild);
    cout << root->val << " ";
    delete root;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,4,3};
  int b[4] = {4,2,1,3};
  vector<int> vec1(a,a+4);
  vector<int> vec2(b,b+4);
  TreeNode* res = s.buildTree(vec1, vec2);
  s.postorder(res);
  cout << endl;
  return 0;
}
