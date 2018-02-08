// clang++ maximumSwap2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  int maximumSwap(int num) {
    string str = to_string(num);
    vector<int> hash(10, 0);
    for (int i = 0; i < str.size(); i++)
      hash[str[i] - '0'] = i;
    for (int i = 0; i < str.size(); i++) {
      for (int j = hash.size() - 1; j >= str[i] - '0'; j--) {
	if (j != str[i] - '0' && hash[j] > i) {
	  swap(str[i], str[hash[j]]);
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
