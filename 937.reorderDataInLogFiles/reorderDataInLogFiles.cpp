class Solution {
public:
    static bool cmp (string s1, string s2) {
        int p1 = s1.find(' '), p2 = s2.find(' ');
        if (!isdigit(s1[p1 + 1]) && !isdigit(s2[p2 + 1])) {
            if (s1.substr(p1 + 1) == s2.substr(p2 + 1)) return s1.substr(0, p1 + 1) < s2.substr(0, p2 + 1);
            else return s1.substr(p1 + 1) < s2.substr(p2 + 1);
        } else {
            if (!isdigit(s1[p1 + 1])) return true;
            else return false;
        }
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res = logs;
        stable_sort(res.begin(), res.end(), cmp);
        return res;
    }
    
};
