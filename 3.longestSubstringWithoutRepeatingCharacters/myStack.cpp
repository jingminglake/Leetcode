#include <iostream>
class MyStack
{
public:
  MyStack(){
    top = 0;
  }
  
  void push(char c) {
    if(top < 49)
     stack[++top] = c;
    else
      std::cout << "stack is full" << std::endl;
  }
  char pop(){
    if(top >= 0){
      char temp = stack[top];
      top--;
      return temp;
    }
    else{
      std::cout << "stack is empty" << std::endl;
      return '#';
    }
  }
  char stack[50];
  int top;
};

int main()
{
  MyStack myStack;
  char c;
  std::cin >> c;
  while(c != '#') {
    myStack.push(c);
    std::cin >> c;
  }
  while (myStack.top > 0) {
    std::cout << myStack.pop() << std::endl;
  }
  return 0;
}
