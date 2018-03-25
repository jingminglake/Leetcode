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
    int getMinimumDifference(TreeNode* root) {
        if (!root)
            return -1;
        int res = INT_MAX;
        int prev = -1;
        inorderHelper(root, res, prev);
        return res;
    }
    void inorderHelper(TreeNode* root, int& res, int& prev) {
        if (!root)
            return;
        inorderHelper(root->left, res, prev);
        if (prev >= 0)
            res = min (res, root->val - prev);
        prev = root->val;
        inorderHelper(root->right, res, prev);
    }
};

int main()
{
  Solution s;
  int tree[6] = {1,9999,5,9999,9999,3};
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
  cout << s.getMinimumDifference(vec[0]);
  cout << endl;
  return 0;
}
