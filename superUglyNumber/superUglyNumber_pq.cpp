// clang++ superUglyNumber_pq.cpp

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> uglys(n);
        int pSize = primes.size();
        uglys[0] = 1;
        auto Comp = [&](const tuple<long, int, int>& p1, const tuple<long, int, int>& p2) {
            return get<0>(p1) > get<0>(p2);
        };
        typedef priority_queue<tuple<long, int, int>, vector<tuple<long, int, int> >, decltype(Comp) > my_pq;
        my_pq pq(Comp);
        for (int i = 0; i < pSize; i++) {
            pq.push(make_tuple(primes[i], 0, primes[i]));
        }
        for (int i = 1; i < n; i++) {
            long minUgly = get<0>(pq.top());
            uglys[i] = minUgly;
            while (!pq.empty() && get<0>(pq.top()) == minUgly) {
                int p = get<1>(pq.top()) + 1;
                int prime = get<2>(pq.top());
                pq.push(make_tuple(uglys[p] * prime, p, prime));
                pq.pop();
            }
        }
        return uglys[n - 1];
    }
};

int main()
{
  Solution s;
  vector<int> primes = {2,7,13,19};
  cout << s.nthSuperUglyNumber(12, primes);
  cout << endl;
  return 0;
}
