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
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    return traverse(root, false);
  }
  int traverse(TreeNode *root, bool l) {
    if (!root)
      return 0;
    if (!root->left && !root->right && l)
      return root->val;
    return traverse(root->left, true) + traverse(root->right, false);
  }
};

int main()
{
  Solution s;
  int tree[8] = {1,-2,-3,1,3,-2,9999,-1};
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
  cout << s.sumOfLeftLeaves(vec[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
