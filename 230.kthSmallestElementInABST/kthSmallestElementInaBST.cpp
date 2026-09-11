#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, int> m;
        int cnt = count(root->left, m);
        if (k <= cnt) {
            return kthSmallest(root->left, k);
        } else if (k > cnt + 1) {
            return kthSmallest(root->right, k - 1 - cnt);
        }
        return root->val;
    }
    int count(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (!root)
            return 0;
        if (m.count(root))
            return m[root];
        int res = count(root->left, m) + count(root->right, m) + 1;
        return m[root] = res;
    }
};

int main()
{
  Solution s;
  int tree[3] = {5,2,13};
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
  cout << s.kthSmallest(vec[0], 3);
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  cout << endl;
  vec.clear();
  return 0;
}
