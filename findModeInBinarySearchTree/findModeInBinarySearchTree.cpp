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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        long prev = LONG_MIN;
        int count = 1;
        int maxCount = 1;
        findModeHelper(root, res, prev, count, maxCount);
        return res;
    }
    void findModeHelper(TreeNode* root, vector<int>& res, long& prev, int& count, int& maxCount) {
        if (!root)
            return;
        findModeHelper(root->left, res, prev, count, maxCount);
        if (prev != LONG_MIN) {
            if (root->val == prev) {
                count++;
            } else {
                count = 1;
            }
        }
        if (count == maxCount) {
            res.push_back(root->val);
        } else if (count > maxCount) {
            res.clear();
            res.push_back(root->val);
            maxCount = count;
        }
        prev = root->val;
        findModeHelper(root->right, res, prev, count, maxCount);
    }
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
