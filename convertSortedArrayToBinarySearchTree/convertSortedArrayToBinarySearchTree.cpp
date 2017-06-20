#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return convert(nums, 0, nums.size()-1);    
  }
  TreeNode* convert(vector<int>& nums, int low, int high) {
    TreeNode *t = NULL;
    if (low <= high) {
      int mid = low + (high-low)/2;
      t = new TreeNode(nums[mid]);
      t->left = convert(nums, low, mid - 1);
      t->right = convert(nums, mid + 1, high);
    }
    return t;
  }
};

int main()
{
  Solution s;
  int tree[7] = {1,2,3,4,5,6,7};
  vector<int> nums(tree, tree+7);
  TreeNode* root = s.sortedArrayToBST(nums);
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *t = q.front();
      if (t->left)
	q.push(t->left);
      if (t->right)
	q.push(t->right);
      cout << t->val << " ";
      q.pop();
      delete t;
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
