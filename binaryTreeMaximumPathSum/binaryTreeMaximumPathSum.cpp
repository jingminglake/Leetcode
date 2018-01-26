#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    if (!root)
      return res;
    maxPathSumHelper(root, res);
    return res;
  }
  int maxPathSumHelper(TreeNode* root, int& res) {
    if (!root)
      return 0;
    int leftMax = maxPathSumHelper(root->left, res);
    int rightMax = maxPathSumHelper(root->right, res);
    int rootMax = root->val;
    if (leftMax > 0)
      rootMax += leftMax;
    else
      leftMax = 0;
    if (rightMax > 0)
      rootMax += rightMax;
    else
      rightMax = 0;
    res = max (rootMax, res);
    return max (leftMax, rightMax) + root->val;
  }
};


int main() {
  Solution s;
  int tree[7] = {10,5,15,9999,9999,6,20};
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
  cout << s.maxPathSum(vec[0]) << endl; 
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
