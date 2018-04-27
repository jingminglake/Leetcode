#include <iostream>
#include <vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string& str : strs) {
            res += to_string(str.length()) + "/" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int start = 0;
        while (start < s.length()) {
            int p = s.find_first_of('/', start);
            int len = stoi(s.substr(start, p - start));
            start = p + 1;
            res.push_back(s.substr(start, len));
            start += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    Codec s;
    vector<string> vec = {"abc","123", "qwe"};
    string str = s.encode(vec);
    cout << str << endl;
    for (string& ss : s.decode(str))
        cout << ss << " ";
    cout << endl;
    return 0;
}
