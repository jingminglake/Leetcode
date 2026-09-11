// clang++ uglyNumberII.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution{
public:
  int nthUglyNumber(int n) {
    int ans = 0;
    priority_queue<long, vector<long>, greater<long> > pq;
    unordered_set<long> set;
    pq.push(1);
    while (n > 0) {
      ans = pq.top();
      pq.pop();
      long n2 = ans * 2;
      long n3 = ans * 3;
      long n5 = ans * 5;
      if (set.find(n2) == set.end()) {
	pq.push(n2);
	set.insert(n2);
      }
      if (set.find(n3) == set.end()) {
	pq.push(n3);
	set.insert(n3);
      }
      if (set.find(n5) == set.end()) {
	pq.push(n5);
	set.insert(n5);
      }
      n--;
    }//for
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.nthUglyNumber(10);
  cout << endl;
  return 0;
}
