#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* str2tree(string s) {
    if (s.empty())
      return NULL;
    auto found = s.find('(');
    int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
    TreeNode *root = new TreeNode(val);
    if (found == string::npos)
      return root;
    int start = found, cnt = 0;
    for (int i = start; i < s.size(); i++) {
      if (s[i] == '(')
	++cnt;
      else if (s[i] == ')')
	--cnt;
      if (cnt == 0 && start == found) {
	root->left = str2tree(s.substr(start + 1, i - start - 1));
	start = i + 1;
      } else if (cnt == 0) {
	root->right = str2tree(s.substr(start + 1, i - start - 1));
      }
    }
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
  string str = "4(2(3)(1))(6(5))";
  TreeNode *root = s.str2tree(str);
  s.preorder(root);
  cout << endl;
  return 0;
}
