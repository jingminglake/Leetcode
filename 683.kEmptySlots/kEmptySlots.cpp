// clang++ kEmptySlots.cpp  -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n)
            return -1;
        ++k;
        int bSize = (n + k - 1) / k;
        vector<int> minBucket(bSize, INT_MAX);
        vector<int> maxBucket(bSize, INT_MIN);
        for (int i = 0; i < n; i++) {
            int pos = flowers[i] / k;
            if (minBucket[pos] > flowers[i]) {
                minBucket[pos] = flowers[i];
                if (pos > 0 && maxBucket[pos - 1] == flowers[i] - k)
                    return i + 1;
            }
            if (maxBucket[pos] < flowers[i]) {
                maxBucket[pos] = flowers[i];
                if (pos < bSize - 1 && minBucket[pos + 1] == flowers[i] + k)
                    return i + 1;
            }
        }
        return -1;
    }
};

int main()
{
  Solution s;
  vector<int> flowers = {1,2,3};
  int k = 1;
  cout << s.kEmptySlots(flowers, k) << endl;;
  return 0;
}
