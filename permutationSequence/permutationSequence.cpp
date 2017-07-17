#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution{
public:
 string getPermutation(int n, int k) {
   string ans;
   string numbers;
   vector<int> factorial(n+1, 1);
   int cumprod = 1;
   for (int i = 1; i <= n; i++) {
     cumprod *= i;
     factorial[i] = cumprod;
     numbers.push_back(i + '0');
   }
   k--;
   for (int i = 1; i <= n; i++) {
     int index = k/factorial[n-i];
     ans += numbers[index];
     numbers.erase(numbers.begin() + index);
     k -= index * factorial[n-i];
   }
   return ans;
  }
};

int main()
{
  Solution s;
  cout << s.getPermutation(3, 3);
  cout << endl;
  return 0;
}
