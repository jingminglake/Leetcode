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
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || (!root->left && !root->right))
      return root;
    TreeNode *newRoot = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;
    return newRoot;
  }
  void preorder(TreeNode* root) {
    if (!root)
      return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
};

int main()
{
  Solution s;
  int tree[5] = {1,2,3,4,5};
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
  TreeNode * res =  s.upsideDownBinaryTree(vec[0]);
  s.preorder(res);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
