// clang++ reconstructItinerary_stack.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string> > neighbors;
        for (auto& ticket : tickets)
            neighbors[ticket.first].insert(ticket.second);
        dfs ("JFK", neighbors, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs (string start, unordered_map<string, multiset<string> >& neighbors, vector<string>& res) {
        stack<string> s;
        s.push(start);
        while (!s.empty()) {
            string cur = s.top();
            if (neighbors[cur].empty()) {
                res.push_back(cur);
                s.pop();
            } else {
                s.push(*neighbors[cur].begin());
                neighbors[cur].erase(neighbors[cur].begin());
            }
        }
    }
};

int main()
{
    Solution s;
    vector<pair<string, string> > tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> res = s.findItinerary(tickets);
    for (string& ss : res)
        cout << ss << " ";
    cout << endl;
    return 0;
}
