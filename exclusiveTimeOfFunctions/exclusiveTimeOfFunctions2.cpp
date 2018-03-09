#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n , 0);
        stack<int> s;
        int preTime = 0;
        for (string log : logs) {
            int funcId = stoi(log.substr(0, log.find_first_of(':')));
            string status = log.substr(log.find_first_of(':') + 1, log.find_last_of(':') - log.find_first_of(':') - 1);
            int curTime = stoi(log.substr(log.find_last_of(':') + 1));
            //cout << funcId << " " << status << " " << curTime << endl;
            if (!s.empty()) {
                if (status == "end") {
                    res[s.top()] += curTime - preTime + 1;
                    s.pop();
                    preTime = curTime;
                } else if (status == "start") {
                    res[s.top()] += curTime - preTime - 1;
                    s.push(funcId);
                    preTime = curTime;
                }
            } else {
                s.push(funcId);
                preTime = curTime;
            }
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
