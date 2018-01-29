class Solution {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int res = 0;
    vector<int> path;
    int depth = 0;
    depthSumInverseHelper(nestedList, depth, path);
    for (int i = 0; i < path.size(); i++) {
      res += path[i] * (path.size() - i);
    }
    return res;
  }
  void depthSumInverseHelper(vector<NestedInteger>& nestedList, int depth, vector<int>& path) {
    if (depth >= path.size())
      path.resize(depth + 1);
    for (NestedInteger& ni : nestedList) {
      if (ni.isInteger()) {
	path[depth] += ni.getInteger();
	continue;
      }
      depthSumInverseHelper(ni.getList(), depth + 1, path);
    }
  }
};
