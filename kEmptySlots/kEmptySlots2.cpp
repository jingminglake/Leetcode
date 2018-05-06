// clang++ kEmptySlots.cpp  -std=c++11

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n)
            return -1;
        set<int> s;
        for (int i = 0; i < n; i++) {
            set<int>::iterator it_r = s.insert(flowers[i]).first;
            set<int>::iterator it_l = it_r;
            if (++it_r != s.end() && *it_r == flowers[i] + k + 1)
                return i + 1;
            if (it_l != s.begin() && *(--it_l) == flowers[i] - k - 1)
                return i + 1;
        }
        return -1;
    }
};

int main()
{
  Solution s;
  vector<int> flowers = {1,2,3};
  int k = 1;
  cout << s.kEmptySlots(flowers, k) << endl;;
  return 0;
}
