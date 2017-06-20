#include <iostream>
#include <vector>
#include <unordered_map>
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
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    if (!root)
      return ans;
    traverse(root, ans);
    return ans;
  }
  void traverse(TreeNode *root, vector<int>& ans) {
    if (!root)
      return;
    traverse(root->left, ans);
    if (root->val == prev)
      count++;
    else
      count = 1;
    if (count > max) {
      max = count;
      ans.clear();
      ans.push_back(root->val);
    } else if (count == max) {
      ans.push_back(root->val);
    }
    prev = root->val;
    traverse(root->right, ans);
  }
  int prev = INT_MAX;
  int count = 1;
  int max = 0;
};

int main()
{
  Solution s;
  int tree[6] = {1,1,2,9999,9999,2};
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
  vector<int> res = s.findMode(vec[0]);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
