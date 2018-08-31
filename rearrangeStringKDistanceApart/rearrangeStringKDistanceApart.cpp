// clang++ rearrangeStringKDistanceApart.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        int len = s.length();
        if (k <= 0)
            return s;
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        priority_queue<pair<int, char> > pq;
        for (auto& p : m)
            pq.emplace(p.second, p.first);
        int index = 0;
        string res(len, ' ');
        while (index < len) {
            int round_size = min (k, len - index);
            vector<pair<int, char> > next;
            if (pq.empty() || pq.size() < round_size)
                return "";
            for (int i = 0; i < round_size; i++) {
                pair<int, char> p = pq.top();
                pq.pop();
                res[index++] = p.second;
                if (p.first - 1 > 0)
                    next.emplace_back(p.first - 1, p.second);
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
