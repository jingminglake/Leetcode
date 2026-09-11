#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long res = 1;
        if (n == 1)
            return res;
        if (primes.size() == 0)
            return res;
        priority_queue<long, vector<long>, greater<long> > pq;
        for (int i = 1; i < n; i++) {
            for (int p : primes) {
                pq.push(p * res);
            }
            while (!pq.empty() && pq.top() == res) {
                pq.pop();
            }
            res = pq.top();
            pq.pop();
        }
        return res;
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
