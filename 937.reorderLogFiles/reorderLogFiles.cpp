class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        if (logs.size() == 0) return res;
        vector<int> digit_logs;
        vector<pair<string, string> > letter_logs;
        for (int i = 0; i < logs.size(); i++) {
            string log = logs[i];
            int index = log.find_first_of(" ");
            string id = log.substr(0, index);
            string words = log.substr(index + 1);
            if (checkLogType(words) == "digits") {
                digit_logs.push_back(i);
            } else if (checkLogType(words) == "letters") {
                letter_logs.push_back({id, words});
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), [](const pair<string, string>& s1, const pair<string, string>& s2) {
            return s1.second < s2.second || (s1.second == s2.second && s1.first < s2.first);
        });
        for (auto& p : letter_logs) res.push_back(p.first + " " + p.second);
        for (int i : digit_logs) res.push_back(logs[i]);
        return res;
    }
    string checkLogType(string& words) {
        for (char c : words) {
            if (c >= '0' && c <= '9')
                return "digits";
            else if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return "letters";
        }
        return "other";
    }
};
