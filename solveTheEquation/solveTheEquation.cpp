#include <iostream>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int res = 0;
        int num_x = 0, sum = 0;
        int sign = 1; // 1 : left of =, -1 : right of =
        int left = 0, right = 0;
        while (right < equation.length()) {
            char c = equation[right];
            if (c == 'x') {
                if (left == right || equation[right - 1] == '+') num_x += sign;
                else if (equation[right - 1] == '-') num_x -= sign;
                else num_x += sign * stoi(equation.substr(left, right - left));
                right++;
                left = right;
            } else if (c == '+' || c == '-') {
                if (right > left) sum += sign * stoi(equation.substr(left, right - left));
                //cout << left << " " << right << endl;
                left = right; // left point to + or -, means str in stoi use operator +,- 
                right++;
            } else if (c == '=') {
                //cout << left << " " << right << endl;
                if (right > left) sum += sign * stoi(equation.substr(left, right - left));
                sign = -1;
                right++;
                left = right;
            } else {
                right++;
            }
        }
        if (left < equation.length()) // there may be a number in the end
            sum += sign * stoi(equation.substr(left));
        if (num_x == 0 && sum == 0) return "Infinite solutions";
        if (num_x == 0 && sum != 0) return "No solution";
        return "x=" + to_string(-sum / num_x);
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
