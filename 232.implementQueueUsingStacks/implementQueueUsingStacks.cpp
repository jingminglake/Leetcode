#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
public:
    MyQueue() {
    
    }
    void push(int x) {
        input.push(x);
    }
    int pop() {
        int res = peek();
        output.pop();
        return res;
    }
    int peek() {
        if (empty())
            return -1;
        if (output.empty()) {
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    bool empty() {
        return input.empty() && output.empty();
    }
    stack<int> input, output;
};

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
