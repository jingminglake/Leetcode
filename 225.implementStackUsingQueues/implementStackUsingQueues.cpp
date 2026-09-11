#include <iostream>
#include <queue>
using namespace std;

class MyStack{
public:
  MyStack() {
    
  }
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  int pop() {
    if (empty())
      return -1;
    int res = q.front();
    q.pop();
    return res;
  }
  int top() {
    return q.front();
  }
  bool empty() {
    return q.empty();
  }
  queue<int> q;
};

int main()
{
   MyStack obj;
   int i = 1;
   while (i < 10)
     obj.push(i++);
   int param_2 = obj.pop();
   int param_3 = obj.top();
   bool param_4 = obj.empty();
   cout << param_2 << " " << param_3 << " " << param_4 << endl;
   return 0;
}
