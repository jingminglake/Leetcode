#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n, 0);
    if (logs.size() == 0 || n < 1)
      return res;
    stack<string> s;
    int prevTime = 0;
    for (int i = 0; i < logs.size(); i++) {
      vector<string> logsi = split(logs[i]);
      if (!s.empty()) {
	res[stoi(s.top())] += stoi(logsi[2]) - prevTime;
      }
      prevTime = stoi(logsi[2]);
      if (logsi[1] == "start") {
	s.push(logsi[0]);
      } else {
	res[stoi(s.top())]++;
	s.pop();
	prevTime++;
      }
    }
    return res;
  }
  vector<string> split(string s) {
    vector<string> res;
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, ':')) {
      res.push_back(temp);
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> logs = {"0:start:0",
			 "1:start:2",
			 "1:end:5",
			 "0:end:6",
  };
  for (int i : s.exclusiveTime(2, logs))
    cout << i << " ";
  cout << endl;
  return 0;
}
