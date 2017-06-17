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
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int main()
{
  Solution s;
  string str = "123#4";
  int size = str.length();
  vector<TreeNode *> vec;
  for (int i = 0; i < size; i++) {
    if (str[i] != '#') {
      vec.push_back(new TreeNode(str[i] - '0'));
    } else {
      vec.push_back(NULL);
    }
  }
  for (int i = 0; i < size/2; i++) {
    if (i*2 + 1 < size)
      vec[i]->left = vec[i*2 + 1];
    if (i*2 + 2 < size)
      vec[i]->right = vec[i*2 + 2];
  }
  cout << s.maxDepth(vec[0]) << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
