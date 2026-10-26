class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int len = temperatures.length;
        int[] res = new int[len];
        Stack<Integer> stk = new Stack<>(); // index of 75, 71, 69,...

        int curtemp = temperatures[0];
        for (int i = 0; i < len; i++) {
            curtemp = temperatures[i];
            while (!stk.isEmpty() && temperatures[stk.peek()] < curtemp) {
                int tempIndex = stk.pop();
                res[tempIndex] = i - tempIndex;
            }
            stk.push(i);
        }
        return res;
    }
}