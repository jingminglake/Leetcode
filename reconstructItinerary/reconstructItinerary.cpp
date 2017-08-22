// clang++ reconstructItinerary.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution{
public:
  vector<string> findItinerary(vector<pair<string, string> >& tickets) {
    for (pair<string, string>& ticket : tickets)
      targets[ticket.first].insert(ticket.second);
    dfs("JFK");
    reverse(route.begin(), route.end());
    return route;
  }
  void dfs(string airport) {
    while (targets[airport].size()) {
      string next = *targets[airport].begin();
      targets[airport].erase(targets[airport].begin());
      dfs(next);
    }
    route.push_back(airport);
  }
private:
  unordered_map<string, multiset<string> > targets;
  vector<string> route;
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
