#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> digits = {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
        int h = digits[0] * 10 + digits[1];
        int m = digits[2] * 10 + digits[3];
        int now = h * 60 + m;
        int cloestTime = now;
        vector<int> cur(4, 0);
        dfs(0, digits, cur, now, cloestTime);
        char buf[5];
        sprintf(buf, "%02d:%02d", cloestTime / 60, cloestTime % 60);
        return string(buf);
    }
    void dfs(int start, vector<int>& digits, vector<int>& cur, int& now, int& cloestTime) {
        if (start == 4) {
            int h = cur[0] * 10 + cur[1];
            int m = cur[2] * 10 + cur[3];
            if (h > 23 || m > 59)
                return;
            int curTime = h * 60 + m;
            if (curTime != now && timeDiff(curTime, now) < timeDiff(cloestTime, now))
                cloestTime = curTime;
            return;
        }
        for (int digit : digits) {
            cur[start] = digit;
            dfs(start + 1, digits, cur, now, cloestTime);
        }
    }
    int timeDiff(int t, int now) {
        if (t == now)
            return INT_MAX;
        return t > now ? t - now : 24 * 60 - (now - t);
    }
};

int main() {
    Solution s;
    string time = "19:31";
    cout << s.nextClosestTime(time) << endl;
    return 0;
}
