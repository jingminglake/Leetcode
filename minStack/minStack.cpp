#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
  MinStack() {
    min.push(INT_MAX);
  }
  void push(int x) {
    s.push(x);
    if (x <= min.top()) {
      min.push(x);
    }
  }
  void pop() {
    if (empty())
      return;
    if(s.top() == min.top())
      min.pop();
    s.pop();
  }
  int top() {
    if (empty())
      return -1; 
    return s.top();
  }
  int getMin() {
    if (empty())
      return 0;
    return min.top();
  }
  bool empty() {
    return s.empty();
  }
  stack<int> s;
  stack<int> min;
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
