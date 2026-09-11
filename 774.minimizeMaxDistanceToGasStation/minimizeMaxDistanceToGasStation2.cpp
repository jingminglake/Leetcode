// clang++ minimizeMaxDistanceToGasStation.cpp  -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 0;
        for (int i = 0; i < stations.size() - 1; i++)
            right = max (right, (double)stations[i + 1] - stations[i]);
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2.0;
            if (splitByMaxLen(stations, mid) <= K)
                right = mid;
            else
                left = mid;
        }
        return left;
    }
    int splitByMaxLen(vector<int>& stations, double maxLen) {
        int res = 0;
        for (int i = 0; i < stations.size() - 1; i++) {
            int gap = stations[i + 1] - stations[i];
            if (gap > maxLen)
                res += int (gap / maxLen);
        }
        return res;
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
