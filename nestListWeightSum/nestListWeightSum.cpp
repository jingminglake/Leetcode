class Solution {
public:
  int depthSum(vector<NestedInteger>& nestedList) {
    int res = 0, depth = 1;
    depthSumHelper(nestedList, res, depth);
    return res;
  }
  void depthSumHelper(vector<NestedInteger>& nestedList, int& res, int depth) {
    for (NestedInteger& ni : nestedList) {
      if (ni.isInteger()) {
	res += ni.getInteger() * depth;
	continue;
      }
      depthSumHelper(ni.getList(), res, depth + 1);
    }
  }
};
