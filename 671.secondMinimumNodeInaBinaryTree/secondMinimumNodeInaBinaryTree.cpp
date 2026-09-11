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
  int findSecondMinimumValue(TreeNode *root) {
    int minV = INT_MAX, secondMinV = INT_MAX;
    traversal(root, minV, secondMinV);
    return secondMinV == INT_MAX ? -1 : secondMinV;
  }
  void traversal(TreeNode* root, int& minV, int& secondMinV) {
    if (!root)
      return;
    if (root->val < minV) {
      if (minV != secondMinV)
	secondMinV = minV;
      minV = root->val;
    } else if (root->val < secondMinV && root->val > minV) {
      secondMinV = root->val;
    }
    traversal(root->left, minV, secondMinV);
    traversal(root->right, minV, secondMinV);
  }
};

int main()
{
  Solution s;
  int tree[7] = {5,3,6,2,4,9999,7};
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
  cout << s.findSecondMinimumValue(vec[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
