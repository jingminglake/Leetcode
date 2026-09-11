class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> level;
        level.push_back(0);
        int res = 0;
        dfs(nestedList, level, 1);
        for (int i = 1; i < level.size(); i++) {
            res += level[i] * (level.size() - i);
        }
        return res;
    }
    void dfs(vector<NestedInteger>& nestedList, vector<int>& level, int depth) {
        for (NestedInteger& ni : nestedList) {
            if (depth == level.size()) level.push_back(0);
            if (ni.isInteger()) level[depth] += ni.getInteger();
            else dfs(ni.getList(), level, depth + 1);
        }
    }
};
