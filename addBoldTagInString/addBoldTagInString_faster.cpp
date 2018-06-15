#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string res;
        if (s.length() == 0)
            return res;
        if (dict.size() == 0)
            return s;
        vector<pair<int, int> > intervals;
        for (string& word : dict) {
            int i = 0;
            while (i < s.length()) {
                int index = s.find(word, i);
                if (index == string::npos)
                    break;
                int len = word.length();
                intervals.emplace_back(index, index + len - 1);
                i = index + 1;
            }
        }
        intervals = mergeIntervals(intervals);
        if (intervals.size() == 0)
            return s;
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (intervals[cur].first == i)
                res += "<b>";
            res += s[i];
            if (intervals[cur].second == i) {
                res += "</b>";
                cur++;
            }
        }
        return res;
    }
    vector<pair<int, int> > mergeIntervals(vector<pair<int, int> >& intervals) {
        vector<pair<int, int> > res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > res.back().second + 1)
                res.push_back(intervals[i]);
            else
                res.back().second = max (res.back().second, intervals[i].second);
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "abcxyz123";
    vector<string> dict = {"abc","123"};
    cout << s.addBoldTag(str, dict) << endl;
    return 0;
}
