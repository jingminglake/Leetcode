#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len_s = S.length();
        vector<int> res(len_s, INT_MAX);
        queue<int> q;
        for (int i = 0; i < len_s; i++) {
            if (S[i] == C) {
                res[i] = 0;
                q.push(i);
            }
        }
        vector<int> dirs = {-1, 1};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int index = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int next_i = index + dir;
                    if (next_i < 0 || next_i >= len_s || res[next_i] <= res[index])
                        continue;
                    res[next_i] = res[index] + 1;
                    q.push(next_i);
                }
            }
        }
        return res;
    }
};

int main() {
    string S = "loveleetcode";
    char C = 'e';
    Solution s;
    for (int n : s.shortestToChar(S, C))
        cout << n << " ";
    cout << endl;
    return 0;
}
