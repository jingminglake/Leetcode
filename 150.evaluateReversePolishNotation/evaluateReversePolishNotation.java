class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> numStack = new Stack<>();
        for (String token : tokens) {
            if (token.equals("+")) {
                int right = numStack.pop();
                int left = numStack.pop();
                numStack.push(left + right);
            } else if (token.equals("-")) {
                int right = numStack.pop();
                int left = numStack.pop();
                numStack.push(left - right);
            } else if (token.equals("*")) {
                int right = numStack.pop();
                int left = numStack.pop();
                numStack.push(left * right);
            } else if (token.equals("/")) {
                int right = numStack.pop();
                int left = numStack.pop();
                numStack.push(left / right);
            } else {
                numStack.push(Integer.valueOf(token));
            }
        }
        return numStack.peek();
    }
}