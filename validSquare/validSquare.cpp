// clang++ validSquare.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution{
public:
  long distance(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<long> s;
    s.insert(distance(p1,p2));
    s.insert(distance(p1,p3));
    s.insert(distance(p1,p4));
    s.insert(distance(p2,p3));
    s.insert(distance(p2,p4));
    s.insert(distance(p3,p4));
    return !s.count(0) && s.size() == 2;
  }
};

int main()
{
  Solution s;
  vector<int> p1 = {0,0};
  vector<int> p2 = {1,1};
  vector<int> p3 = {1,0};
  vector<int> p4 = {0,1};
  cout << s.validSquare(p1,p2,p3,p4);
  cout << endl;
  return 0;
}
