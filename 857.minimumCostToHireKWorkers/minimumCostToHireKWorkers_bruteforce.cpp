// greedy + brutefore
// time complexity : o(n^2)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const tuple<int, double, int>& t1, const tuple<int, double, int>& t2) {
            return get<0>(t1) < get<0>(t2);
        }
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<tuple<int, double, int> > workers; // 0 -> quality, 1 -> w / q, 2 -> index
        for (int i = 0; i < n; i++) {
            workers.emplace_back(quality[i], 1.0 * wage[i] / quality[i], i);
        }
        sort(workers.begin(), workers.end(), Compare());
        double mincost = numeric_limits<double>::max();
        for (int base = 0; base < n; base++) {
            double candidate_cost = wage[base];
            double base_wq = 1.0 * wage[base] / quality[base];
            int cnt = 1;
            for (int i = 0; i < n; i++) {
                if (get<1>(workers[i]) > base_wq || get<2>(workers[i]) == base) {
                    continue;
                }
                if (candidate_cost > mincost || cnt == K)
                    break;
                candidate_cost += get<0>(workers[i]) * base_wq;
                cnt++;
            }
            if (cnt == K)
                mincost = min (mincost, candidate_cost);
        }
        return mincost;
    }
};

int main() {
    Solution s;
    vector<int> quality = {10,20,5}, wage = {70,50,30};
    int K = 2;
    cout << s.mincostToHireWorkers(quality, wage, K) << endl;
    return 0;
}
