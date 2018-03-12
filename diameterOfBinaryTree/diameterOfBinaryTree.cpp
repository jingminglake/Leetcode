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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (!root)
            return res;
        res = 1;
        diameterOfBinaryTreeHelper(root, res);
        return res - 1;
    }
    int diameterOfBinaryTreeHelper(TreeNode* root, int& res) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int leftR = diameterOfBinaryTreeHelper(root->left, res);
        int rightR = diameterOfBinaryTreeHelper(root->right, res);
        res = max(res, leftR + rightR + 1);
        return max(leftR, rightR) + 1;
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
