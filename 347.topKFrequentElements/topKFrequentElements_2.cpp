#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums)
            m[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > pq;
        for (auto& p : m) {
            pq.emplace(p);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[6] = {1, 1, 1, 2, 2, 3};
    vector<int> vec(a, a+6);
    vector<int> res = s.topKFrequent(vec, 2);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
