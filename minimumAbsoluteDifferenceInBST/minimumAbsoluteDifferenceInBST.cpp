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
  int getMinimumDifference(TreeNode* root) {
    int ans;
    if (!root)
      return ans;
    ans = INT_MAX;
    int prev = INT_MAX;
    traverse(root, ans, prev);
    return ans;
  }
  void traverse(TreeNode *root, int& ans, int &prev) {
    if (!root)
      return;
    traverse(root->left, ans, prev);
    if (prev != INT_MAX)
      ans = min(abs(root->val - prev), ans);
    prev = root->val;
    traverse(root->right, ans, prev);
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
