#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  TreeNode* trimBST(TreeNode *root, int L, int R) {
    if (!root)
      return root;
    return trimHelper(root, L, R, true);
  }
  TreeNode* trimHelper(TreeNode *root, int L, int R, bool top) {
    if (!root)
      return root;
    root->left = trimHelper(root->left, L, R, false);
    root->right = trimHelper(root->right, L, R, false);
    if (root->val >= L && root->val <= R)
      return root;
    TreeNode *result = root->val < L ? root->right : root->left;
    if (!top)
      delete root;
    return result;
  }
  void preorder(TreeNode *root) {
    if (!root)
      return;
    TreeNode *rootLeft = root->left;
    TreeNode *rootRight = root->right;
    cout << root->val << endl;
    delete root;
    preorder(rootLeft);
    preorder(rootRight);
  }
};

int main()
{
  Solution s;
  int tree[3] = {1,0,2};
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
  TreeNode* t = s.trimBST(vec[0], 1, 2);
  s.preorder(t);
  vec.clear();
  return 0;
}
