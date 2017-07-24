#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool isValidBST(TreeNode *root) {
    return isValid(root, LONG_MAX, LONG_MIN);
  }
  bool isValid(TreeNode *root, long minV, long maxV) {
    if (!root)
      return true;
    if (root->val >= maxV || root->val <= minV)
      return false;
    return isValid(root->left, minV, root->val) && isValid(root->right, root->val, maxV);
  }
};

int main()
{
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
  cout << s.isValidBST(vec[0]) << endl; 
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
