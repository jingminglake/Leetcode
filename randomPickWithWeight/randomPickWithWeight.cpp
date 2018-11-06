#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> w) {
        preSum = w;
        for (int i = 1; i < w.size(); i++) {
            preSum[i] += preSum[i - 1];
        }
        srand(time(0));
    }
    
    int pickIndex() {
        int len = preSum.size();
        if (len == 0)
            return -1;
        int w = rand() % preSum.back() + 1;
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (preSum[mid] < w) {
                left = mid + 1;
            } else if (preSum[mid] > w) {
                right = mid;
            } else {
                return mid;
            }
        }
        return left;
    }
    vector<int> preSum;
};

int main() {
    vector<int> w = {1, 3};
    Solution s(w);
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    cout << s.pickIndex() << endl;
    return 0;
}
