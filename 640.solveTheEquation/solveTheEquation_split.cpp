#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find("=");
        string left = equation.substr(0, pos), right = equation.substr(pos + 1);
       /* cout << left << " " << right << endl;
        string delim = "+-";
        for (string& str : splitByMulti(equation, delim))
            cout << str << " ";
        cout << endl; */
        vector<int> left_res = evalExp(left);
        vector<int> right_res = evalExp(right);
        vector<int> res(2, 0);
        res[0] = left_res[0] - right_res[0];
        res[1] = right_res[1] - left_res[1];
        //cout << res[0] << " " << res[1] << endl;
        if (res[0] == 0 && res[1] == 0) return "Infinite solutions";
        if (res[0] == 0) return "No solution";
        return "x=" + to_string(res[1] / res[0]);
    }
    vector<string> splitByMulti(string& str, string delim) {
        vector<string> tokens;
        int left = 0, right = 0; 
        while ((right = str.find_first_of(delim, left)) != string::npos) {
            int start = left > 0 ? left - 1 : 0;
            tokens.push_back(str.substr(start, right - start));
            left = right + 1;
        }
        if (left < str.length()) {
            int start = left > 0 ? left - 1 : 0;
            tokens.push_back(str.substr(start));
        }
        //for (string& str : tokens)
        //    cout << str << "===";
        return tokens;
    }
    vector<int> evalExp(string exp) {
        vector<int> res(2, 0);
        string delim = "+-";
        //cout << exp << endl;
        vector<string> tokens = splitByMulti(exp, delim);
        for (string token : tokens) {
            //cout << token << endl;
            if (token.empty())
                continue;
            if (token == "+x" || token == "x") res[0] += 1;
	        else if (token == "-x") res[0] -= 1;
	        else if (token.find("x") != string::npos) res[0] += stoi(token.substr(0, token.find("x")));
	        else res[1] += stoi(token);
        }
        return res;
    }
};


int main() {
    Solution s;
    string e1 = "x+5-3+x=6+x-2";
    string e2 = "x=x";
    string e3 = "2x=x";
    string e4 = "2x+3x-6x=x+2";
    string e5 = "x=x+2";
    cout << s.solveEquation(e1) << endl;
    cout << s.solveEquation(e2) << endl;
    cout << s.solveEquation(e3) << endl;
    cout << s.solveEquation(e4) << endl;
    cout << s.solveEquation(e5) << endl;
    return 0;
}
