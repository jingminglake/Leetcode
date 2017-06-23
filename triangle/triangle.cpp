#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int minimumTotal(vector<vector<int> >& triangle) {
    int size = triangle.size();
    vector<int> m(triangle.back());
    for (int i = size-2; i >= 0; i--) {
      int sizeR = triangle[i].size();
      for (int j = 0; j < sizeR; j++) {
	m[j] = min(m[j], m[j+1]) + triangle[i][j];
      }
    }
    return m[0];
  }
};

int main()
{
  Solution s;
  int a1[1] = {2};
  int a2[2] = {3,4};
  int a3[3] = {6,5,7};
  int a4[4] = {4,1,8,3};
  vector<int> vec1(a1, a1+1);
  vector<int> vec2(a2, a2+2);
  vector<int> vec3(a3, a3+3);
  vector<int> vec4(a4, a4+4);
  vector<vector<int> > triangle;
  triangle.push_back(vec1);
  triangle.push_back(vec2);
  triangle.push_back(vec3);
  triangle.push_back(vec4);
  cout << s.minimumTotal(triangle);
  cout << endl;
  return 0;
}
