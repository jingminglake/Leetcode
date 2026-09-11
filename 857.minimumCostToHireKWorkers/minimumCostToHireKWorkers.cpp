#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int> > workers;
        for (int i = 0; i < quality.size(); i++)
            workers.emplace_back(1.0 * wage[i] / quality[i], quality[i]);
        sort(workers.begin(), workers.end());
        double res = std::numeric_limits<double>::max();
        int quality_sum = 0;
        priority_queue<int> pq;
        for (auto& worker : workers) {
            quality_sum += worker.second;
            pq.push(worker.second);
            if (pq.size() > K) {
                quality_sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                res = min (res, quality_sum * worker.first);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> quality = {10,20,5}, wage = {70,50,30};
    int K = 2;
    cout << s.mincostToHireWorkers(quality, wage, K) << endl;
    return 0;
}
