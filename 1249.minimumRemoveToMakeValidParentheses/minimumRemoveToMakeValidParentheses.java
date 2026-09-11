class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> leftRemainIndex = new Stack<Integer>();
        boolean[] removeFlag = new boolean[s.length()];
        int rightRemain = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                leftRemainIndex.push(i);
            } else if (c == ')') {
                if (!leftRemainIndex.isEmpty()) {
                    leftRemainIndex.pop();
                } else {
                    removeFlag[i] = true; // remove remain ')'
                }
            }
        }
        while (!leftRemainIndex.isEmpty()) {
            removeFlag[leftRemainIndex.peek()] = true;
            leftRemainIndex.pop();
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!removeFlag[i]) sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}
