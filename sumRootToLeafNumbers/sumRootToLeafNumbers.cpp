#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int sumNumbers(TreeNode *root) {
    return sum(root, 0);
  }
  int sum(TreeNode *root, int preSum) {
    if (!root)
      return 0;
    if (!root->left && !root->right) {
      return preSum * 10 + root->val;
    }
    return sum(root->left, preSum * 10 + root->val) + sum(root->right, preSum * 10 + root->val);
  }
};

int main()
{
  Solution s;
  int tree[3] = {1, 2, 3};
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
  cout << s.sumNumbers(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
