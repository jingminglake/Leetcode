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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ans;
    if (!p || !q)
      return ans;
    ans = root;
    int minV = min(p->val, q->val);
    int maxV = max(p->val, q->val);
    while (ans) {
      if (ans->val > maxV)
	ans = ans->left;
      else if (ans->val < minV)
	ans = ans->right;
      else
	return ans;
    }
    return ans;
  }
  bool checkExist(vector<int>& nums, TreeNode* p, TreeNode* q){
  }
};

int main()
{
  Solution s;
  int tree[11] = {6,2,8,0,4,7,9,9999,9999,3,5};
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
  cout << s.lowestCommonAncestor(vec[0], vec[1], vec[4])->val << endl;
  return 0;
}
