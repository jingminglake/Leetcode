class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        maxV = INT_MIN;
        s = new stack<int>;
    }
    
    void push(int x) {
        if (x >= maxV) {
            s->push(maxV);
            maxV = x;
        }
        s->push(x);
    }
    
    int pop() {
        if (s->empty())
            return -1;
        int res = -1;
        if (s->top() == maxV) {
            res = s->top();
            s->pop();
            maxV = s->top();
            s->pop();
        } else {
            res = s->top();
            s->pop();
        }
        return res;
    }
    
    int top() {
        if (s->empty())
            return -1;
        return s->top(); 
    }
    
    int peekMax() {
        if (!s->empty())
            return maxV;
    }
    
    int popMax() {
        int res = maxV;
        stack<int> temp;
        while (!s->empty()) {
            if (s->top() == maxV) {
                s->pop();
                maxV = s->top();
                s->pop();
                break;
            } else {
                temp.push(s->top());
                s->pop();
            }
        }
        while (!temp.empty()) {
            if (temp.top() >= maxV) {
                s->push(maxV);
                maxV = temp.top();
            }
            s->push(temp.top());
            temp.pop();
        }
        return res;
    }
    stack<int>* s;
    int maxV;
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
