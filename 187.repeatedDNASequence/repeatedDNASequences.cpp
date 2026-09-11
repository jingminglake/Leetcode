// clang++ repeatedDNASequences.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
class Solution{
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    vector<string> ans;
    unordered_set<string> seqSet, tempAnsSet;
    pair<unordered_set<string>::iterator, bool> p;
    for (int i = 0; i + 9 < len; i++) {
      string seq = s.substr(i, 10);
      p = seqSet.insert(seq);
      if (!p.second)
	tempAnsSet.insert(seq);
    }
    unordered_set<string>::iterator it = tempAnsSet.begin();
    while (it != tempAnsSet.end()) {
      ans.push_back(*it);
      ++it;
    }
    return ans;
  }
  }; */
class Solution{
public:
  vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    vector<string> ans;
    unordered_map<string, int> seqMap;
    for (int i = 0; i + 9 < len; i++) {
      string seq = s.substr(i, 10);
      if (++seqMap[seq] == 2)
	ans.push_back(seq);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> res = s.findRepeatedDnaSequences(s1);
  for (string &ss : res)
    cout << ss << " ";
  cout << endl;
  return 0;
}
