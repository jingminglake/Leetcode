#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
  int findClosestLeaf(TreeNode* root, int k) {
    unordered_map<TreeNode*, TreeNode*> backMap;   // store all edges that trace node back to its parent
    queue<TreeNode*> q;          // the queue used in BFS
    unordered_set<TreeNode*> visited;             // store all visited nodes
        
    // DFS: search for node whoes val == k
    TreeNode* kNode = DFS(root, k, backMap);
    q.push(kNode);
    visited.insert(kNode);
        
    // BFS: find the shortest path
    while(!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();
      if(!curr->left && !curr->right) {
	return curr->val;
      }
      if(curr->left && !visited.count(curr->left) ) {
	q.push(curr->left);
	visited.insert(curr->left);
      }
      if(curr->right && !visited.count(curr->right) ) {
	q.push(curr->right);
	visited.insert(curr->right);
      }
      if(backMap.count(curr) && !visited.count(backMap[curr])) {  // go alone the back edge
	q.push(backMap[curr]);
	visited.insert(backMap[curr]);
      }
    }
    return -1; // never hit
  }
    
  TreeNode* DFS(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& backMap) {
    if(root->val == k) {
      return root;
    }
    if(root->left) {
      backMap.insert(make_pair(root->left, root));        // add back edge
      TreeNode* left = DFS(root->left, k, backMap);
      if(left) 
	return left;
    }
    if(root->right) {
      backMap.insert(make_pair(root->right, root));       // add back edge
      TreeNode* right = DFS(root->right, k, backMap);
      if(right) 
	return right;
    }
    return NULL;
  }
};


int main() {
  Solution s;
  string str = "123#4####5";
  int size = str.length();
  vector<TreeNode *> vec;
  for (int i = 0; i < size; i++) {
    if (str[i] != '#') {
      vec.push_back(new TreeNode(str[i] - '0'));
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
  cout << s.findClosestLeaf(vec[0], 2) << endl;
  return 0;
}
