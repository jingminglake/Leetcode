// clang++ rearrangeStringKDistanceApart.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0)
            return s;
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        priority_queue<pair<int, char> > pq;
        for (auto& p : m)
            pq.push({p.second, p.first});
        int len = s.length();
        string res;
        while (!pq.empty()) {
            vector<pair<int, char> > next;
            int n = min (k, len);
            for (int i = 0; i < n; i++) {
                if (pq.empty())
                    return "";
                pair<int, char> p = pq.top();
                pq.pop();
                res += p.second;
                if (--p.first > 0)
                    next.push_back(p);
                len--;
            }
            for (auto& p : next)
                pq.push(p);
        }
        return res;
    }
};

int main()
{
  Solution s;
  string str = "aaadbbcc";
  int k = 2;
  cout << s.rearrangeString(str, k) << endl;;
  return 0;
}
