#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int n : nums1)
            m[n]++;
        for (int n : nums2) {
            if (m.count(n) && --m[n] >= 0)
                res.push_back(n);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[4] = {1,2,2,1};
    int b[2] = {2,2};
    vector<int> vec1(a, a+4);
    vector<int> vec2(b, b+2);
    vector<int> ans = s.intersect(vec1, vec2);
    vector<int>::iterator it = ans.begin();
    while (it != ans.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
