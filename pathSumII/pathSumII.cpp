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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;
    vector<int> path;
    traversal(root, path, sum, ans);
    return ans;
  }
  void traversal(TreeNode *root, vector<int>& path, int target, vector<vector<int> >& ans) {
    if (!root)
      return;
    path.push_back(root->val);
    if (!root->left && !root->right) {
      if(target == root->val) {
	ans.push_back(path);
	path.pop_back();
	return;
      }
    }
    traversal(root->left, path, target - root->val, ans);
    traversal(root->right, path, target - root->val, ans);
    path.pop_back();
  }
};

int main()
{
  Solution s;
  int tree[15] = {5, 4, 8, 11, 9999, 13, 4, 7, 2, 9999, 9999, 9999, 9999, 5, 1};
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
  vector<vector<int> > res = s.pathSum(vec[0], 22);
  for (vector<int> & v : res) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
