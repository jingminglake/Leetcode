// clang++ findKPairsWithSmallestSums.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > res;
        if (nums1.size() == 0 || nums2.size() == 0 || k == 0)
            return res;
        auto comp = [&] (const tuple<int, int, int64_t>& t1, const tuple<int, int, int64_t>& t2) {
            return get<2>(t1) > get<2>(t2);
        };
        typedef priority_queue<tuple<int, int, int64_t>, vector<tuple<int, int, int64_t> >, decltype(comp) > my_pq;
        my_pq pq(comp);
        for (int i = 0; i < nums2.size(); i++) {
            pq.emplace(0, i, nums1[0] + nums2[i]);
        }
        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                tuple<int, int, int64_t> t = pq.top();
                pq.pop();
                int x = get<0>(t), y = get<1>(t);
                res.emplace_back(nums1[x], nums2[y]);
                if (x + 1 < nums1.size())
                    pq.emplace(x + 1, y, nums1[x + 1] + nums2[y]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,1,2};
    vector<int> nums2 = {1,2,3};
    vector<vector<int> > matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    vector<pair<int,int> > res = s.kSmallestPairs(nums1, nums2, 3);
    for (pair<int, int>& p : res)
        cout << "(" << p.first << ", " << p.second << ")";
    cout << endl;
    return 0;
}
