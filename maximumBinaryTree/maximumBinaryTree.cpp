#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);
  }
  TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int left, int right) {
    if (left > right)
      return nullptr;
    if (left == right)
      return new TreeNode(nums[left]);
    int indexOfMax = left;
    int maxNum = nums[left];
    for (int i = left + 1; i <= right; i++) {
      if (nums[i] > maxNum) {
	maxNum = nums[i];
	indexOfMax = i;
      }
    }
    TreeNode *root = new TreeNode(nums[indexOfMax]);
    root->left = constructMaximumBinaryTreeHelper(nums, left, indexOfMax - 1);
    root->right = constructMaximumBinaryTreeHelper(nums, indexOfMax + 1, right);
    return root;
  }
  void preorder(TreeNode* root) {
    if (!root)
      return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
};


int main() {
  Solution s;
  vector<int> arr = {3,2,1,6,0,5};
  TreeNode *root = s.constructMaximumBinaryTree(arr);
  s.preorder(root);
  cout << endl;
  return 0;
}
