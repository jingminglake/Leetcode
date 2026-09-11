#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> dist_left(n, n + 1), dist_right = dist_left;
        queue<int> q_left, q_right;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L') {
                q_left.push(i);
                dist_left[i] = 0;
            }
            else if (dominoes[i] == 'R') {
                q_right.push(i);
                dist_right[i] = 0;
            }
        }
        bfs(dominoes, q_left, dist_left, -1);
        bfs(dominoes, q_right, dist_right, 1);
        string res(n, '.');
        for (int i = 0; i < n; i++) {
            if (dist_left[i] < dist_right[i]) {
                res[i] = 'L';
            } else if (dist_left[i] > dist_right[i]) {
                res[i] = 'R';
            }
        }
        return res;
    }
    void bfs(string& dominoes, queue<int>& q, vector<int>& dist, int dir) {
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int index = q.front();
                q.pop();
                int next_index = index + dir;
                if (next_index < 0 || next_index >= dominoes.size() || dominoes[next_index] != '.')
                    continue;
                dist[next_index] = dist[index] + 1;
                q.push(next_index);
            }
        }
    }
};

int main() {
    Solution s;
    string dominoes = ".L.R...LR..L..";
    cout << s.pushDominoes(dominoes) << endl;
    return 0;
}
