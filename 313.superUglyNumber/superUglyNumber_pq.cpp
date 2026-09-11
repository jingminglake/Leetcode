// clang++ superUglyNumber_pq.cpp

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int64_t> res(n, 1);
        auto comp = [&](const tuple<int, int, int64_t>& t1, const tuple<int, int, int64_t>& t2) {
            return get<2>(t1) > get<2>(t2);
        };
        typedef priority_queue<tuple<int, int, int64_t>, vector<tuple<int, int, int64_t> >, decltype(comp) > my_pq;
        my_pq pq(comp);
        for (int prime : primes)
            pq.emplace(prime, 0, prime);
        int64_t cur_min = 1;
        for (int i = 1; i < n; i++) {
            cur_min = res[i] = get<2>(pq.top());
            while (!pq.empty() && get<2>(pq.top()) == cur_min) {
                int prime = get<0>(pq.top());
                int index = get<1>(pq.top());
                pq.emplace(prime, index + 1, prime * res[index + 1]);
                pq.pop();
            }
        }
        return res[n - 1];
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
