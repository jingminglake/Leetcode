#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  int numSquares(int n) {
    if (n <= 0)
      return 0;
    queue<int> q;
    q.push(n);
    int depth = 0;
    while (!q.empty()) {
      depth++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
	int curr = q.front();
	q.pop();
	for (int j = 1; j * j <= curr; j++) {
	  int remain = curr - j * j;
	  if (remain == 0) {
	    return depth;
	  } else if (remain > 0) {
	    q.push(remain);
	  } else if (remain < 0) {
	    break;
	  }
	}
      }
    }//while
    return depth;
  }
};

int main()
{
  Solution s; 
  cout << s.numSquares(13) << endl;
  return 0;
}
