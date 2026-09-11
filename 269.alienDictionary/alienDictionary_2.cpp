#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, unordered_set<char> > neighbors;
        for (int i = 1; i < words.size(); i++) {
            pair<int, int> p = getOrderPair(words[i - 1], words[i]);
            if (p != pair<int, int>()) {
                neighbors[p.first].insert(p.second);
            }
        }
        unordered_set<char> nodes;
        for (string& word : words) {
            for (char c : word)  nodes.insert(c);
        }
        unordered_map<char, int> indegree;
        for (auto& neighbor : neighbors) {
            for (char c : neighbor.second) {
                indegree[c]++;
            }
        }
        queue<char> q;
        for (char n : nodes) {
            if (indegree[n] == 0) q.push(n);
        }
        string res;
        int cnt = nodes.size();
        while (!q.empty()) {
            char node = q.front(); q.pop();
            cnt--;
            res += node;
            for (char neighbor : neighbors[node]) {
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return cnt == 0 ? res : "";
    }
    pair<char, char> getOrderPair(string& word1, string& word2) {
        for (int i = 0; i < min(word1.size(), word2.size()); i++) {
            if (word1[i] != word2[i]) return {word1[i], word2[i]};
        }
        return {};
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
