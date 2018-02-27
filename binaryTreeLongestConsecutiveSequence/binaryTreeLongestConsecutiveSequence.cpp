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

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        if (!root)
            return res;
        int curMax = 0;
        longestConsecutiveHelper(root, res, INT_MIN, curMax);
        return res;
    }
    void longestConsecutiveHelper(TreeNode* root, int& res, int target, int curMax) {
        if (!root)
            return;
        if (root->val == target)
            curMax++;
        else
            curMax = 1;
        res = max (res, curMax);
        longestConsecutiveHelper(root->left, res, root->val + 1, curMax);
        longestConsecutiveHelper(root->right, res, root->val + 1, curMax);
    }
};

int main()
{
  Solution s;
  int tree[7] = {1,2,2,9999,9999,3,7};
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
  cout << s.longestConsecutive(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
