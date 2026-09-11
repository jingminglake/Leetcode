#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.size() == 0)
            return 0;
        unordered_map<string, int> m;
        vector<int> colCnt(picture[0].size(), 0);
        for (int i = 0; i < picture.size(); i++) {
            string key;
            int cnt = 0;
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    cnt++;
                    colCnt[j]++;
                }
                key += picture[i][j];
            }
            if (cnt == N)
                m[key]++;
        }
        int res = 0;
        for (auto& p : m) {
            if (p.second == N) {
                for (int j = 0; j < p.first.size(); j++) {
                    if (p.first[j] == 'B' && colCnt[j] == N)
                        res += N;
                }
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<vector<char> > picture = {{'W', 'B', 'W', 'B', 'B', 'W'},
				    {'W', 'B', 'W', 'B', 'B', 'W'},
				    {'W', 'B', 'W', 'B', 'B', 'W'},
				    {'W', 'W', 'B', 'W', 'B', 'W'}};
  int N = 3;
  cout << s.findBlackPixel(picture, N) << endl;
  return 0;
}
