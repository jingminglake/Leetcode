// clang++ reconstructItinerary.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> res;
        if (tickets.size() == 0)
            return res;
        unordered_map<string, multiset<string> > neighbors;
        for (pair<string, string>& ticket : tickets) {
            neighbors[ticket.first].insert(ticket.second);
        }
        dfs(res, "JFK", neighbors);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(vector<string>& res, string start, unordered_map<string, multiset<string> >& neighbors) {
        while (!neighbors[start].empty()) {
            string next = *neighbors[start].begin();
            neighbors[start].erase(neighbors[start].begin()); // remove just one
            dfs(res, next, neighbors);
        }
        res.push_back(start);
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
