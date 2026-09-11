#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string> > res;
    if (accounts.size() == 0)
      return res;
    unordered_map<string, string> email2name;
    for (vector<string>& account : accounts) {
      email2name[account[1]] = account[0];
      for (int i = 2; i < account.size(); i++) {
	union_op(account[1], account[i]);
	email2name[account[i]] = account[0];
      }
    }
    unordered_map<string, vector<string> > email2email;
    for (auto &p : email2name) {
      email2email[find_op(p.first)].push_back(p.first);
    }
    for (auto &p : email2email) {
      vector<string> temp;
      temp.push_back(email2name[p.first]);
      sort(p.second.begin(), p.second.end());
      temp.insert(temp.begin() + 1, p.second.begin(), p.second.end());
      res.push_back(temp);
    }
    return res;
  }
  string find_op(string email) {
    if (!father.count(email) || father[email] == email) {
      father[email] = email;
      return email;
    }
    return father[email] = find_op(father[email]);
  }
  void union_op(string email1, string email2) {
    string father1 = find_op(email1);
    string father2 = find_op(email2);
    if (father1 == father2)
      return;
    father[father1] = father2;
  }
  unordered_map<string, string> father;
};

int main()
{
  Solution s;
  vector<vector<string> > accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
  for (vector<string>& vec : s.accountsMerge(accounts))
    for (string ss : vec)
      cout << ss << " ";
  cout << endl;
  return 0;
}
