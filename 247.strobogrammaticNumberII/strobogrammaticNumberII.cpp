#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n), res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};

int main()
{
  Solution s;
  for(string ss : s.findStrobogrammatic(10)) {
      cout << ss << " ";
  }
  cout << endl;
  return 0;
}
