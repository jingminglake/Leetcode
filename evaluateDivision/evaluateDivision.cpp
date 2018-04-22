#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<string> > edges;
        unordered_map<string, vector<double> > edgesValue;
        for (int i = 0; i < equations.size(); i++) {
            edges[equations[i].first].push_back(equations[i].second);
            edgesValue[equations[i].first].push_back(values[i]);
            edges[equations[i].second].push_back(equations[i].first);
            edgesValue[equations[i].second].push_back(1 / values[i]);
        }
        vector<double> res(queries.size(), 0.0);
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            double curValue = 1.0;
            res[i] = dfs(queries[i].first, queries[i].second, visited, edges, edgesValue, curValue);
            if (res[i] == 0.0)
                res[i] = -1.0;
        }
        return res;
    }
    double dfs(string start, string end, unordered_set<string>& visited, unordered_map<string, vector<string> >& edges, unordered_map<string, vector<double> >& edgesValue, double curValue) {
        if (!edges.count(start))
            return 0.0;
        if (visited.count(start))
            return 0.0;
        if (start == end)
            return curValue;
        visited.insert(start);
        for (int i = 0; i < edges[start].size(); i++) {
            double tmp = dfs(edges[start][i], end, visited, edges, edgesValue, curValue * edgesValue[start][i]);
            if (tmp != 0.0)
                return tmp;
        }
        visited.erase(start);
        return 0.0;
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
