class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, level = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '(') level++;
            else level--;
            if (S[i] == ')' && S[i - 1] == '(')
                res += 1 << level;
        }
        return res;
    }
};
