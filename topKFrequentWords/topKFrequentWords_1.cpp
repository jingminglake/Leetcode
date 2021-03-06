#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) const{
            return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        if (words.size() == 0)
            return res;
        unordered_map<string, int> m;
        for (string& word : words)
            m[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int> >, Compare> pq;
        for (auto& p : m) {
            if (pq.size() < k)
                pq.emplace(p.first, p.second);
            else {
                if (pq.top().second < p.second || (pq.top().second == p.second && pq.top().first > p.first) ) {
                    pq.pop();
                    pq.emplace(p.first, p.second);
                }
            }
        }
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
  Solution s;
  vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> words2 = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  for (string& str : s.topKFrequent(words1, 2)) {
    cout << str << " ";
  }
  cout << endl;
  for (string& str : s.topKFrequent(words2, 4)) {
    cout << str << " ";
  }
  cout << endl;
}
