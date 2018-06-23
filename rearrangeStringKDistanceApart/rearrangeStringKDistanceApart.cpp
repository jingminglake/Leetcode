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
        string res(s.length(), ' ');
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        priority_queue<pair<int, char> > pq;
        for (auto& p : m) {
            pq.emplace(p.second, p.first);
        }
        int index = 0;
        int len = s.length();
        while (!pq.empty()) {
            if (pq.size() < min(k, len))
                return "";
            vector<pair<int, char> > next;
            for (int i = 0; i < min (k, len); i++) {
                pair<int, char> p = pq.top();
                pq.pop();
                res[index++] = p.second;
                if (p.first - 1 > 0)
                    next.emplace_back(p.first - 1, p.second);
                len--;
            }
            for (auto& p : next) {
                pq.emplace(p.first, p.second);
            }
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
