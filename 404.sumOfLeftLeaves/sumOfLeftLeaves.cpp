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
    int res = 0;
    if (!root)
      return res;
    sumOfLeftLeavesHelper(root, res, false);
    return res;
  }
  void sumOfLeftLeavesHelper(TreeNode* root, int& res, bool isLeft) {
    if (!root)
      return;
    if (isLeft && !root->left && !root->right) {
      res += root->val;
      return;
    }
    sumOfLeftLeavesHelper(root->left, res, true);
    sumOfLeftLeavesHelper(root->right, res, false);
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
