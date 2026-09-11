#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s;
        int prevTime = 0;
        for (string log : logs) {
            int id = stoi(log.substr(0, log.find_first_of(':')));
            string status = log.substr(log.find_first_of(':') + 1, log.find_last_of(':') - log.find_first_of(':') - 1);
            int curTime = stoi(log.substr(log.find_last_of(':') + 1));
            if (s.empty()) {
                s.push(id);
                prevTime = curTime;
            } else {
                if (status == "end") {
                    res[s.top()] += curTime - prevTime + 1;
                    s.pop();
                    prevTime = curTime + 1;
                } else if (status == "start") {
                    res[s.top()] += curTime - prevTime;
                    s.push(id);
                    prevTime = curTime;
                }
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
