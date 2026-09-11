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
  vector<int> preorderTraversal(TreeNode *root) {
    /*vector<int> ans;
    if (!root)
      return ans;
    ans.push_back(root->val);
    vector<int> ansLeft = preorderTraversal(root->left);
    ans.insert(ans.end(), ansLeft.begin(), ansLeft.end());
    vector<int> ansRight = preorderTraversal(root->right);
    ans.insert(ans.end(), ansRight.begin(), ansRight.end());
    return ans;*/
    vector<int> ans;
    stack<TreeNode*> s;
    while (root) {
      ans.push_back(root->val);
      if (root->right)
	s.push(root->right);
      root = root->left;
      if (!root && !s.empty()) {
	root = s.top();
	s.pop();
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int tree[6] = {1, 9999, 2, 9999, 9999, 3};
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
  vector<int> res = s.preorderTraversal(vec[0]);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
