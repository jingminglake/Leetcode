// clang++ canIWin.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((maxChoosableInteger + 1) * maxChoosableInteger < 2 * desiredTotal)
            return false;
        unordered_map<int, bool> m;
        return dfs(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool dfs(int& maxChoosableInteger, int desiredTotal, int used, unordered_map<int, bool>& m) {
        if (m.count(used))
            return m[used];
        for (int i = maxChoosableInteger; i >= 1; i--) {
            if ((used & (1 << i)) != 0)
                continue;
            int next_used = used | (1 << i);
            if (i >= desiredTotal || !dfs(maxChoosableInteger, desiredTotal - i, next_used, m)) 
                return m[used] = true;
        }
        return m[used] = false;
    }
};

int main()
{
    Solution s;
    cout << s.canIWin(10, 11) << endl;
    return 0;
}
