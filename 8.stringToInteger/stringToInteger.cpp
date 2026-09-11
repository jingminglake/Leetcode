#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int i = 0;
        int sign = 1;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') sign = -1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') {
            res *= 10;
            res += (int) (str[i] - '0');
            i++;
            if (res * sign > INT_MAX)
                return INT_MAX;
            else if(res * sign < INT_MIN)
                return INT_MIN; 
        }
        return res * sign;  
    }
};

int main()
{
    Solution s;
    string ss = "-1123111111111111111";
    //int a = atoi(ss.c_str());
  
    cout << s.myAtoi(ss) << endl;
    return 0;
}
