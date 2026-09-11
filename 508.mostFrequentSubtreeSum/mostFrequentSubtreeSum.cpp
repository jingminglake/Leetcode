#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    vector<int> ans;
    if (!root)
      return ans;
    map<int, int> m;
    treeSum(root, m);   
    map<int, int>::iterator it = m.begin();
    int mostFreSum = it->second;
    while (it != m.end()) {
      if (it->second > mostFreSum)
	mostFreSum = it->second;
      ++it;
    }
    it = m.begin();
    while (it != m.end()) {
      if (it->second == mostFreSum)
	ans.push_back(it->first);
      ++it;
    }  
    return ans;
  }
  int treeSum(TreeNode *root, map<int, int>& sumMap) {
    if (!root) {
      return 0;
    }
    int sum = root->val + treeSum(root->left, sumMap) + treeSum(root->right, sumMap);
    sumMap[sum]++;
    return sum;
  }
};

int main()
{
  Solution s;
  int tree[12] = {1,2,3,4,9999,5,6,9999,9999,9999,9999,7};
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
  vector<int> res = s.findFrequentTreeSum(vec[0]);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  for (TreeNode *t : vec) {
    //cout << t->val << " ";
    delete t;
  }
  vec.clear();
  return 0;
}
