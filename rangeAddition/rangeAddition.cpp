#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (vector<int>& v : updates) {
            int start = v[0];
            int end = v[1];
            int inc = v[2];
            res[start] += inc;
            if (end + 1 < length)
                res[end + 1] -= inc;
        }
        for (int i = 1; i < length; i++)
            res[i] += res[i - 1];
        return res;
    }
};

int main() {
  Solution s;
  vector<vector<int> > updates = { {1,3,2}, {2,4,3}, {0,2,-2}};
  for (int i : s.getModifiedArray(5, updates))
    cout << i << " ";
  cout << endl;
  return 0;
}
