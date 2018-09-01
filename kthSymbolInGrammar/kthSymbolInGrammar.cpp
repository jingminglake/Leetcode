#include <iostream>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1)
            return 0;
        if (K % 2 == 0)
            return kthGrammar(N - 1, K / 2) == 0 ? 1 : 0;
        else 
            return kthGrammar(N - 1, (K + 1) / 2) == 0 ? 0 : 1;
    }
};

int main() {
    Solution s;
    cout << s.kthGrammar(5, 10) << endl;
    return 0;
}
