class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (char c : S) {
            if (res.back() == c) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
