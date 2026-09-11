#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = -1;
        if (s2.empty()) {
            adjust();
        }
        if (!s2.empty()) {
            res = s2.top(); s2.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            adjust();
        }
        return s2.top();
    }
    
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
    void adjust() {
        while (!s1.empty()) {
            s2.push(s1.top()); s1.pop();
        }
    }
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue obj;
    int i = 1;
    while (i < 10)
        obj.push(i++);
    int param_2 = obj.pop();
    int param_3 = obj.peek();
    bool param_4 = obj.empty();
    cout << param_2 << " " << param_3 << " " << param_4 << endl;
    return 0;
}
