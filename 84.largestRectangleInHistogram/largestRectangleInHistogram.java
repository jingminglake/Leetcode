class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stk = new Stack<>();
        stk.push(-1);

        int res = 0;
        int n = heights.length;
        
        // i == n 时候使用高度0清空栈
        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n) ? 0 : heights[i];
            while (stk.peek() != -1 && heights[stk.peek()] >= curHeight) {
                int height = heights[stk.pop()];

                int leftBoundary = stk.peek();
                int width = i - leftBoundary - 1;

                res = Math.max(res, height * width);
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
}