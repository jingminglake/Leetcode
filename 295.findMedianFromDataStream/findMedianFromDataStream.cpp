// clang++ findMedianFromDataStream.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder{
public:
  MedianFinder() {
    
  }
  void addNum(int num) {
    /*if (leftQ.empty() || num <= leftQ.top()) {
      leftQ.push(num);
      if (leftQ.size() - 2 == rightQ.size()) {
        rightQ.push(-leftQ.top());
        leftQ.pop();
      }
    } else {
      rightQ.push(-num);
      if (leftQ.size() < rightQ.size()) {
	leftQ.push(-rightQ.top());
	rightQ.pop();
	} 
    } */
    leftQ.push(num);
    rightQ.push(-leftQ.top());
    leftQ.pop();
    if (leftQ.size() < rightQ.size()) {
	leftQ.push(-rightQ.top());
	rightQ.pop();
    }
  }
  double findMedian() {
    return (leftQ.size() > rightQ.size()) ? leftQ.top() : (leftQ.top() - rightQ.top()) / 2.0;
  }
  priority_queue<long> leftQ, rightQ;
};

int main()
{
  MedianFinder mf;
  mf.addNum(1);
  mf.addNum(2);
  cout << mf.findMedian() << endl;
  mf.addNum(3);
  cout << mf.findMedian() << endl;
  return 0;
}
