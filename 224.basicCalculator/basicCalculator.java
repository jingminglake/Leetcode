class Solution {
    public int calculate(String s) {
        int res = 0;
        int number = 0;
        int sign = 1;
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (c == ' ') {
                continue;
            } else if (Character.isDigit(c)) {
                number = number * 10 + c - '0';
            } else if (c == '+') {
                res += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                res += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                // 1. save current context to stack
                stk.push(res);
                stk.push(sign);

                // 2. reset context
                res = 0;
                number = 0;
                sign = 1;
            } else if (c == ')') {
                // update result
                res += sign * number;
                number = 0;

                // recover outer context 
                int outerSign = stk.pop();
                int outerRes = stk.pop();

                res = outerRes + outerSign * res;
                sign = 1;
            }
        }

        // commit last
        res += sign * number;
        return res;
    }
}