#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> lessThan20 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string numberToWords(int num) {
        if (num == 0)
            return lessThan20[0];
        string res = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000) {
                res = less1000helper(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
            i++;
        }
        res.erase(0,res.find_first_not_of(" "));  
        res.erase(res.find_last_not_of(" ") + 1); 
        return res;
    }
    string less1000helper(int num) {
        if (num == 0)
            return "";
        if (num < 20)
            return lessThan20[num] + " ";
        else if (num < 100)
            return tens[num / 10] + " " + less1000helper(num % 10);
        else
            return lessThan20[num / 100] + " Hundred " + less1000helper(num % 100);
    }
};

int main()
{
  Solution s;
  cout << s.numberToWords(27137) << endl;
  return 0;
}
