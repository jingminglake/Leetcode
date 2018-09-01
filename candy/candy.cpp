#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if  (n == 0)
            return 0;
        vector<int> candys(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candys[i] = candys[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                candys[i] = max (candys[i], candys[i + 1] + 1);
        }
        int res = 0;
        for (int c : candys)
            res += c;
        return res;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {1, 0, 2};
    cout << s.candy(ratings) << endl;
    return 0;
}
