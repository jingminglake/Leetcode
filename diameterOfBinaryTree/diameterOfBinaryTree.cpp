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
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    if (!root)
      return diameter;
    diameterOfBinaryTreeHelper(root, diameter);
    return diameter - 1;
  }
  int diameterOfBinaryTreeHelper(TreeNode* root, int& diameter) {
    if (!root)
      return 0;
    int res = 1;
    int leftRes = diameterOfBinaryTreeHelper(root->left, diameter);
    int rightRes = diameterOfBinaryTreeHelper(root->right, diameter);
    if (root->left) {
      res = max (res, leftRes + 1);
    }
    if (root->right) {
      res = max (res, rightRes + 1);
    }
    diameter = max (diameter, leftRes + rightRes + 1);
    diameter = max (diameter, res);
    return res;
  }
};

int main()
{
  Solution s;
  int tree[4] = {1,2,3,4};
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
  cout << s.diameterOfBinaryTree(vec[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
