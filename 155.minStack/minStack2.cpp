#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minV = INT_MAX;
    }
    
    void push(int x) {
        if (x <= minV) {
            s.push(minV);
            minV = x;
        }
        s.push(x);
    }
    
    void pop() {
        if (!s.empty()) {
            if (s.top() == minV) {
                s.pop();
                minV = s.top();
            }
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minV;
    }
    int minV;
    stack<int> s;
};

int main()
{
    MinStack obj;
    int i = 1;
    while (i < 10)
        obj.push(i++);
    obj.pop();
    int param_3 = obj.top();
    bool param_4 = obj.getMin();
    cout << param_3 << " " << param_4 << endl;
    return 0;
}
