#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> s(J.begin(), J.end());
        for (char c : S) {
            if (s.count(c))
                res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    string J = "aA", S = "aAAbbb";
    cout << s.numJewelsInStones(J, S) << endl;
    return 0;
}
