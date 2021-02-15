#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int res = 0;
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        for (auto& p : m) {
            if (k == 0) {
                if (p.second > 1) res++;
            } else {
                if (m.count(p.first + k)) res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[5] = {1,3,1,5,4};
    vector<int> vec(a, a+5);
    cout << s.findPairs(vec, 0);
    cout << endl;
    return 0;
}
