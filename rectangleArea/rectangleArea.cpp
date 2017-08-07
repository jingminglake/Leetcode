#include <iostream>
using namespace std;

class Solution{
public:
  double computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int areaRect1 = (C-A) * (D-B);
    int areaRect2 = (G-E) * (H-F);
    int left = max(A, E);
    int right = min(G, C);
    int bottom = max(B, F);
    int top = min(D, H);
    int overlap = 0;
    if (right > left && top > bottom)
      overlap = (right - left) * (top - bottom);
    return areaRect1 + areaRect2 - overlap;
  }
};

int main()
{
  Solution s;
  cout << s.computeArea(-3,0,3,4,0,-1,9,2) << endl;
  return 0;
}
