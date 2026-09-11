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
  bool checkEqualTree(TreeNode* root) {
    if (!root)
      return false;
    unordered_map<TreeNode*, int> m;
    int sum = getSum(root, m);
    if (sum % 2 != 0)
      return false;
    for (auto& p : m) {
      if (p.first == root)
	continue;
      if (p.second == sum / 2)
	return true;
    }
    return false;
  }
  int getSum(TreeNode* root, unordered_map<TreeNode*, int>& m) {
    if (!root)
      return 0;
    int leftS = 0, rightS = 0;
    if (m.count(root->left)) {
      leftS = m[root->left];
    }
    else if (root->left){
      leftS = getSum(root->left, m);
      m[root->left] = leftS;
    }
    if (m.count(root->right)) {
      leftS = m[root->right];
    }
    else if (root->right){
      rightS = getSum(root->right, m);
      m[root->right] = rightS;
    }
    int sum = root->val + leftS + rightS;
    m[root] = sum;
    return sum;
  }
};

int main()
{
  Solution s;
  int tree[7] = {5,10,10,9999,9999,2,3};
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
  cout <<  s.checkEqualTree(vec[0]);
  cout << endl;
  for (TreeNode *t : vec) {
    delete t;
  }
  vec.clear();
  return 0;
}
