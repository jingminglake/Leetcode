#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int res = 0;
        if (picture.size() == 0)
            return res;
        vector<int> rows(picture.size(), 0);
        vector<int> cols(picture[0].size() , 0);
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[0].size(); j++) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<vector<char> > picture = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
  cout << s.findLonelyPixel(picture) << endl;
  return 0;
}
