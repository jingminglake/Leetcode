#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0)
            return "";
        // build map, use node->node(edges), nodes, adjacency list (neighbors)
        set<pair<char, char> > edges;
        unordered_set<char> nodes;
        unordered_map<char, set<char> > neighbors;
        string prev = "";
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < min (prev.size(), words[i].size()); j++) {
                if (prev[j] != words[i][j]) {
                    edges.insert(make_pair(prev[j], words[i][j]));
                    neighbors[prev[j]].insert(words[i][j]);
                    break;
                }
            }
            nodes.insert(words[i].begin(), words[i].end());
            prev = words[i];
        }
        //count indegree
        unordered_map<char, int> indegree;
        for (auto& p : edges) {
            indegree[p.second]++;
        }
        // topology sort
        int count = nodes.size();
        string res;
        queue<char> q;
        for (char node : nodes) {
            if (indegree[node] == 0)
                q.push(node);
        }
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            count--;
            res += node;
            //cout << res << endl;
            for (char neighbor : neighbors[node]) {
                //cout << neighbor << "-=-=-=" << indegree[neighbor]  << endl;
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return count == 0 ? res : "";
    }
};

int main()
{
  Solution s;
  vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
  cout << s.alienOrder(words);
  cout << endl;
  return 0;
}
