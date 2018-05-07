// clang++ minimizeMaxDistanceToGasStation.cpp  -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        if (stations.size() < 2)
            return 0;
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2.0;
            if (canSplit(mid, stations, K))
                right = mid;
            else
                left = mid;
        }
        return left;
    }
    bool canSplit(double maxLen, vector<int>& stations, int K) {
        int num = 0;
        for (int i = 0; i < stations.size() - 1; i++) {
            num += (stations[i + 1] - stations[i]) / maxLen;
        }
        return num <= K;
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
