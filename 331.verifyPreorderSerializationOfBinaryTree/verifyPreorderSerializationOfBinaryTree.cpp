#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream iss(preorder);
        string str;
        int indegree = 1;
        while (getline(iss, str, ',')) {
            if (--indegree < 0)
                return false;
            if (str != "#") {
                indegree += 2;
            }
        }
        return indegree == 0;
    }
};

int main() {
  Solution s;
  string ss = "9,3,4,#,#,1,#,#,2,#,6,#,#";
  cout << s.isValidSerialization(ss) << endl;
  return 0;
}
