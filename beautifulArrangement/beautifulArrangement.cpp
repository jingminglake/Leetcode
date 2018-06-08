#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        int res = 0;
        vector<int> visited(N + 1, false);
        dfs(N, visited, res, 1);
        return res;
    }
    void dfs (int& N, vector<int>& visited, int& res, int index) {
        if (index - 1 == N) {
            res++;
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (visited[i])
                continue;
            if (i % index != 0 && index % i != 0)
                continue;
            visited[i] = true;
            dfs (N, visited, res, index + 1);
            visited[i] = false;
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
