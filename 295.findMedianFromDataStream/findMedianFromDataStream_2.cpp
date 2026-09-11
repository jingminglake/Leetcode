// clang++ findMedianFromDataStream.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftQ.push(num);
        rightQ.push(leftQ.top());
        leftQ.pop();
        if (leftQ.size() < rightQ.size()) {
            leftQ.push(rightQ.top());
            rightQ.pop();
        }
    }
    
    double findMedian() {
        if (leftQ.empty())
            return -1.0;
        if (leftQ.size() == rightQ.size())
            return ( leftQ.top() + rightQ.top() ) / 2.0;
        else
            return leftQ.top();
    }
    priority_queue<long> leftQ;
    priority_queue<long, vector<long>, greater<long> > rightQ;
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
