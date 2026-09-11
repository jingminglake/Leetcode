class Solution {
public:
    static bool cmp (pair<string, string>& log1, pair<string, string>& log2) {
        return log1.second == log2.second ? log1.first < log2.first : log1.second < log2.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitLogs;
        vector<pair<string, string>> letterLogs;
        for(string &s : logs) {
            int i = s.find(' ');
            if (isalpha(s[i + 1])) {
                letterLogs.push_back({s.substr(0, i), s.substr(i + 1)});
            } else {
                digitLogs.push_back(s);
            }           
        }
        sort(letterLogs.begin(), letterLogs.end(), cmp);
        for (auto& s : letterLogs) res.push_back(s.first + " " + s.second);
        for (string& s : digitLogs) res.push_back(s);
        return res;
    }
    
};
