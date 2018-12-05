class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string& email : emails) {
            string key = "";
            bool ignore = false;
            for (int i = 0; i < email.length(); i++) {
                char c = email[i];
                if (c == '+') {
                    ignore = true;
                } else if (c == '@') {
                    key += email.substr(i);
                    break;
                }
                if (!ignore && c != '.')
                    key += c;
            }
            //cout << key << endl;
            s.insert(key);
        }
        return s.size();
    }
};
