class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        maxVal = INT_MIN;
    }
    
    void push(int x) {
        if (x >= maxVal) {
            stk.push(maxVal);
            maxVal = x;
        }
        stk.push(x);
    }
    
    int pop() {
        int res = INT_MIN;
        if (!stk.empty()) {
            res = stk.top();
            stk.pop();
            if (res == maxVal) {
                maxVal = stk.top();
                stk.pop();
            }
        }
        return res;
    }
    
    int top() {
        int res = INT_MIN;
        if (!stk.empty()) {
            res = stk.top();
        }
        return res;
    }
    
    int peekMax() {
        return !stk.empty() ? maxVal : INT_MIN;
    }
    
    int popMax() {
        if (stk.empty()) return INT_MIN;
        int prevMax = maxVal;
        stack<int> tmpS;
        while (!stk.empty()) {
            int val = stk.top();
            stk.pop();
            if (val == maxVal) {
                maxVal = stk.top();
                stk.pop();
                break;
            } else {
                tmpS.push(val);
            }
        }
        while (!tmpS.empty()) {
            int val2 = tmpS.top();
            tmpS.pop();
            if (val2 >= maxVal) {
                stk.push(maxVal);
                maxVal = val2;
            }
            stk.push(val2);
        }
        return prevMax;
    }
    stack<int> stk;
    int maxVal;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
