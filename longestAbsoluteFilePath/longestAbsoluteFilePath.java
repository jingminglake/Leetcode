class Solution {
    public int lengthLongestPath(String input) {
        Stack<Integer> stk = new Stack<>();
        int res = 0;
        for (String s : input.split("\n")) {
            int level = s.lastIndexOf("\t") + 1; // number of '\t', level example: 0,1,2,3...
            int len = s.length() - level + 1; //  +1 for '/'
            if (stk.empty()) { // level must be 0 here
                stk.push(len);
            } else {
                if (level == stk.size()) { // cur node in next level
                    int prevLen = stk.empty() ? 0 : stk.peek();
                    stk.push(len + prevLen);
                } else if (level == stk.size() - 1) { // cur node pre node in same level 
                    stk.pop();
                    int prevLen = stk.empty() ? 0 : stk.peek();
                    stk.push(len + prevLen);
                } else if (level < stk.size() - 1) {  // cur node in prev level
                    while (level < stk.size() - 1) stk.pop();
                    stk.pop();
                    int prevLen = stk.empty() ? 0 : stk.peek();
                    stk.push(len + prevLen);
                } else {
                    return -1;
                }
            }
            if (s.contains(".")) res = Math.max(res, stk.peek() - 1);
        }
        return res;
    }
}
