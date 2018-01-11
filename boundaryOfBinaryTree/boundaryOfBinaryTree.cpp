#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    if (root->left || root->right) res.push_back(root->val);
    leftBoundary(root->left, res);
    leaves(root, res);
    rightBoundary(root->right, res);
    return res;
  }
  void leftBoundary(TreeNode* node, vector<int>& res) {
    if (!node || (!node->left && !node->right)) return;
    res.push_back(node->val);
    if (!node->left) leftBoundary(node->right, res);
    else leftBoundary(node->left, res);
  }
  void rightBoundary(TreeNode* node, vector<int>& res) {
    if (!node || (!node->left && !node->right)) return;
    if (!node->right) rightBoundary(node->left, res);
    else rightBoundary(node->right, res);
    res.push_back(node->val);
  }
  void leaves(TreeNode* node, vector<int>& res) {
    if (!node) return;
    if (!node->left && !node->right) {
      res.push_back(node->val);
    }
    leaves(node->left, res);
    leaves(node->right, res);
  }
};

int main()
{
  Solution s;
  int tree[7] = {3,9,20,9999,9999,15,7};
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
  for (int i : s.boundaryOfBinaryTree(vec[0]))
    cout << i << " ";
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
