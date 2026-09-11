class MinStack {
    Stack<Integer> stk;
    Stack<Integer> minS;
    public MinStack() {
        stk = new Stack<>();
        minS = new Stack<>();
    }

    public void push(int value) {
        stk.push(value);
        if (minS.isEmpty()) {
            minS.push(value);
        } else {
            int peek = minS.peek();
            if (value <= peek) {
                minS.push(value);
            }
        }
    }

    public void pop() {
        int value = stk.pop();
        if (minS.peek() == value) {
            minS.pop();
        }
    }

    public int top() {
        return stk.peek();
    }

    public int getMin() {
        return minS.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */