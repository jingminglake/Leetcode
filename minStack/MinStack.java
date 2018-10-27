class MinStack {

    /** initialize your data structure here. */
    public MinStack() {
        s = new Stack<Integer>();
        minS = new Stack<Integer>();
    }
    
    public void push(int x) {
        if (minS.isEmpty() || minS.peek() >= x) {
            minS.push(x);
        }
        s.push(x);
    }
    
    public void pop() {
        if (!s.isEmpty()) {
            if (s.peek().equals(minS.peek()))
                minS.pop();
            s.pop();
        }
        //printS(minS);
    }
    
    public int top() {
        int res = -1;
        if (!s.isEmpty())
            res = s.peek();
        return res;
    }
    public void printS(Stack<Integer> s) {
        Stack<Integer> ss = (Stack)s.clone();
        while (!ss.isEmpty()) {
            System.out.print(ss.pop() + " ");
        }
        System.out.println();
    }
    public int getMin() {
        int res = -1;
        if (!minS.isEmpty())
            res = minS.peek();
        return res;
    }
    Stack<Integer> s;
    Stack<Integer> minS;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
