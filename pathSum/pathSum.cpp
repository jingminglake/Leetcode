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
  bool hasPathSum(TreeNode *root, int sum) {
     if (!root)
       return false;
     int remain = sum - root->val;
     if (!root->left && !root->right && remain == 0)
       return true;
     else
       return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
  }
};

int main()
{
  Solution s;
  int tree[15] = {5,4,8,11,9999,13,4,7,2,9999,9999,9999,9999,9999,1};
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
  cout << s.hasPathSum(vec[0], 22) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
