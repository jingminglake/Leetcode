// clang++ fractionToRecurringDecimal.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator > 0) ^ (denominator > 0)) res += "-";
        long N = labs(numerator);
        long D = labs(denominator);
        if (N % D == 0) return res + to_string(N / D);
        
        // left part
        res += to_string(N / D) + ".";
        N = N % D;
        
        // right part
        long reminder = N;
        unordered_map<long, int> reminderM;
        string rightPart;
        int index = 0;
        while (reminder != 0) {
            if (reminderM.count(reminder)) {
                rightPart.insert(reminderM[reminder], "(");
                rightPart.push_back(')');
                break;
            }
            reminderM[reminder] = index++; // 记录此时计算位置
            
            N *= 10; // 此时N必小于D，先补一个0， 不上0
            while (N < D) { // 如果不够，那么继续补0，并上0
                N *= 10;
                rightPart += "0"; // 上0
                index++;
            }
            rightPart += to_string(N / D); // 上数
            reminder = N % D; // 下一个余数
            N = reminder;
        }
        res += rightPart;
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(-1, -2147483648);
    cout << endl;
    return 0;
}
