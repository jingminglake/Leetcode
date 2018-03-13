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
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        int res = 1;
        // pair.first --> increase res; pair.second --> decrease res
        longestConsecutiveHelper(root, res);
        return res;
    }
    pair<int, int> longestConsecutiveHelper(TreeNode* root, int& res) {
        if (!root)
            return make_pair(0, 0);
        pair<int, int> curRes = make_pair(1, 1);
        if (root->left) {
            pair<int, int> leftR = longestConsecutiveHelper(root->left, res);
            if (root->val - root->left->val == 1)
                curRes.second = leftR.second + 1;
            else if (root->val - root->left->val == -1)
                curRes.first = leftR.first + 1;
        }
        if (root->right) {
            pair<int, int> rightR = longestConsecutiveHelper(root->right, res);
            if (root->val - root->right->val == 1)
                curRes.second = max (curRes.second, rightR.second + 1);
            else if (root->val - root->right->val == -1)
                curRes.first = max (curRes.first, rightR.first + 1);
        }
        res = max (res, curRes.first + curRes.second - 1);
        return curRes;
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
