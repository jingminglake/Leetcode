class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        return dfs(nestedList, 1);
    }
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) res += depth * ni.getInteger();
            else res += dfs(ni.getList(), depth + 1);
        }
        return res;
    }
};
