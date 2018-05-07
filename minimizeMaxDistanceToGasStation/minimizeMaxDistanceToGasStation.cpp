// clang++ minimizeMaxDistanceToGasStation.cpp  -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        if (n < 2)
            return 0;
        auto comp = [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first * 1.0 / p1.second < p2.first * 1.0 / p2.second;
        };
        typedef priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> my_pq;
        my_pq pq(comp);
        for (int i = 0; i < n - 1; i++) {
            pq.push({stations[i + 1] - stations[i], 1});
        }
        for (int i = 0; i < K; i++) {
            pair<int, int> p = pq.top();
            pq.pop();
            p.second++;
            pq.push(p);
        }
        return pq.top().first * 1.0 / pq.top().second;
    }
};

int main()
{
  Solution s;
  vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 9;
  cout << s.minmaxGasDist(stations, k) << endl;;
  return 0;
}
