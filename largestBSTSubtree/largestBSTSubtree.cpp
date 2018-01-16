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

class Solution{
public:
  int largestBSTSubtree(TreeNode* root) {
    int res = 0;
    unordered_map<TreeNode*, int> m;
    countSize(root, m);
    unordered_map<TreeNode*, bool> m2;
    long maxV = LONG_MIN, minV = LONG_MAX;
    isBST(root, m2);
    for (auto& p : m) {
      //cout << p.second << "  " <<  m2[p.first] << endl;
      if (p.second > res && m2[p.first]) {
	res = p.second;
      }
    }
    return res;
  }
  pair<long, long> isBST(TreeNode* root, unordered_map<TreeNode*, bool>& m2) {
    pair<long, long> res = make_pair(LONG_MAX, LONG_MIN);
    if (!root) {
      m2[root] = true;
      return res;
    }
    pair<long, long> leftR = isBST(root->left, m2);
    pair<long, long> rightR = isBST(root->right, m2);
    if (m2[root->left] && m2[root->right] && root->val > leftR.second && root->val < rightR.first) {
      m2[root] = true;
    }
    else {
      m2[root] = false;
    }
    if (m2[root]) {
      res.first = res.second = root->val;
      res.first = min<long> (leftR.first, res.first);
      res.second = max<long> (rightR.second, res.second);
      //cout << res.first << "   " << res.second << endl;
    }
    return res;
  }
  int countSize(TreeNode* root, unordered_map<TreeNode*, int>& m) {
    if (!root)
      return 0;
    int leftR = countSize(root->left, m);
    int rightR = countSize(root->right, m);
    m[root]  = leftR + rightR + 1;
    return m[root];
  }
};

int main()
{
  Solution s;
  int tree[7] = {10,5,15,1,8,9999,7};
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
  cout << s.largestBSTSubtree(vec[0]) << endl; 
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
