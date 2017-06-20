#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxDistance(vector<vector<int> >& arrays) {
    int ans = INT_MIN;
    int size = arrays.size();
    int minE = arrays[0][0];
    int maxE = arrays[0][arrays[0].size() - 1];
    for (int i = 1; i < size; i++) {
      int len = arrays[i].size();
      ans = max(ans, abs(arrays[i][0] - maxE));
      ans = max(ans, abs(arrays[i][len-1] - minE));
      minE = min(minE, arrays[i][0]);
      maxE = max(maxE, arrays[i][len-1]);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > vec;
  int a[3] = {1,2,3};
  int b[2] = {4,5};
  int c[3] = {1,2,3};
  vector<int> vec1(a, a+3);
  vector<int> vec2(b, b+2);
  vector<int> vec3(c, c+3);
  vec.push_back(vec1);
  vec.push_back(vec2);
  vec.push_back(vec3);
  cout << s.maxDistance(vec);
  cout << endl;
  return 0;
}
