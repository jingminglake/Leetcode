#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<bool> visited(N + 1, false);
        dfs(N, 1, visited, res);
        return res;
    }
    void dfs(int N, int level, vector<bool>& visited, int& res) {
        if (level == N + 1) {
            res++;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (i % level == 0 || level % i == 0)) {
                visited[i] = true;
                dfs(N, level + 1, visited, res);
                visited[i] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.countArrangement(3);
    cout << endl;
    return 0;
}
