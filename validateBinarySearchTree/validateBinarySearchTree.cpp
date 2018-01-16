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
  bool isValidBST(TreeNode* root) {
    long max = LONG_MIN;
    return isValidHelper(root, max);
  }
  bool isValidHelper(TreeNode* root, long& max) {
    if (!root)
      return true;
    bool leftRes = isValidHelper(root->left, max);
    if (root->val <= max)
      return false;
    else
      max = root->val;
    bool rightRes = isValidHelper(root->right, max);
    return leftRes && rightRes;
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
