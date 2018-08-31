#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> m;
        for (char c : S)
            m[c]++;
        priority_queue<pair<int, char> > pq;
        for (auto& p : m)
            pq.emplace(p.second, p.first);
        int len = S.length();
        int index = 0;
        string res(len, ' ');
        while (index < len) {
            int round_size = min (2, len - index);
            if (pq.empty() || pq.size() < round_size)
                return "";
            vector<pair<int, char> > next;
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

int main() {
    Solution s;
    string S = "aab";
    cout << s.reorganizeString(S) << endl;
    return 0;
}
