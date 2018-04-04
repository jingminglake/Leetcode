#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) {
                if (--k % 2 == 0)
                    res.push_back(i++);
                else
                    res.push_back(j--);
            } else {
                res.push_back(i++);
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  for (int i : s.constructArray(3, 2)) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
