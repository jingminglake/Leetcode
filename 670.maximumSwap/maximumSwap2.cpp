// clang++ maximumSwap2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  int maximumSwap(int num) {
    string str = to_string(num);
    vector<int> hash(10, 0);
    for (int i = 0; i < str.length(); i++) {
      hash[str[i] - '0'] = i;
    }
    for (int i = 0; i < str.length(); i++) {
      for (int j = 9; j > str[i] - '0'; j--) {
	if (hash[j] > i) {
	  swap (str[hash[j]], str[i]);
	  return stoi(str);
	}
      }
    }
    return stoi(str);
  }
};

int main()
{
  Solution s;
  cout << s.maximumSwap(98368) << endl;
  cout << s.maximumSwap(9973) << endl;
  return 0;
}
