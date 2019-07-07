class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        int cur = 0;
        for (char c : S) {
            if (c == '(') {
                stk.push(cur);
                cur = 0;
            } else {
                cur = max(cur * 2, 1) + stk.top();
                stk.pop();
            }
        }
        return cur;
    }
};
