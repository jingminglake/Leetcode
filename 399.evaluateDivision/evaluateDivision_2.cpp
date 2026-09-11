#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1.0);
        unordered_map<string, vector<pair<string, double> > > neighbors;
        for (int i = 0; i < equations.size(); i++) {
            neighbors[equations[i].first].emplace_back(equations[i].second, values[i]);
            neighbors[equations[i].second].emplace_back(equations[i].first, 1.0 / values[i]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (!neighbors.count(queries[i].first) || !neighbors.count(queries[i].second))
                continue;
            double equation_res = 1.0;
            unordered_set<string> visited;
            //visited.insert(queries[i].first);
            if (dfs(queries[i].first, queries[i].second, neighbors, equation_res, visited)) {
                res[i] = equation_res;
            }
        }
        return res;
    }
    bool dfs(string start, string& end, unordered_map<string, vector<pair<string, double> > >& neighbors, double& res, unordered_set<string>& visited) {
        if (start == end)
            return true;
        visited.insert(start);
        for (auto& n : neighbors[start]) {
            if (visited.count(n.first))
                continue;
            res *= n.second;
            //visited.insert(n.first);
            if (dfs(n.first, end, neighbors, res, visited))
                return true;
            res /= n.second;
            //visited.erase(n.first);
        }
        visited.erase(start);
        return false;
    }
};

int main() {
    Solution s;
    vector<pair<string, string> > equations = {make_pair("a", "b"), make_pair("b", "c")};
    vector<double> values = {2.0, 3.0};
    vector<pair<string, string> > queries = {make_pair("a", "c"), make_pair("b", "a"), make_pair("a", "e"), make_pair("a", "a"),make_pair("x", "x")};
    for (double& d : s.calcEquation(equations, values, queries)) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}
