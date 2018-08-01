#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double> > > edges;
        for (int i = 0; i < equations.size(); i++) {
            edges[equations[i].first].emplace_back(equations[i].second, values[i]);
            edges[equations[i].second].emplace_back(equations[i].first, 1 / values[i]);
        }
        vector<double> res(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); i++) {
            if (!edges.count(queries[i].first) || !edges.count(queries[i].second)) {
                continue;
            }
            unordered_set<string> visited;
            double curValue = 1.0;
            visited.insert(queries[i].first);
            if (dfs(queries[i].first, queries[i].second, visited, edges, curValue))
                res[i] = curValue;
            visited.erase(queries[i].first);
        }
        return res;
    }
    bool dfs(string start, string& end, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double> > >& edges, double& curValue) {
        if (start == end)
            return true;
        for (int i = 0; i < edges[start].size(); i++) {
            if (!visited.count(edges[start][i].first)) {
                visited.insert(edges[start][i].first);
                curValue *= edges[start][i].second;
                if (dfs(edges[start][i].first, end, visited, edges, curValue))
                    return true;
                visited.erase(edges[start][i].first);
                curValue /= edges[start][i].second;
            }
        }
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
