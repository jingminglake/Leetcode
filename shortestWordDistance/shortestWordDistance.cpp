#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int res = INT_MAX;
    int m = -1, n = -1;
    for (int i = 0; i < words.size(); i++) {
      if (word1 == words[i]) {
	m = i;
	if (n != -1) {
	  res = min (res, abs(m - n));
	}
      } 
      if (word2 == words[i]) {
	n = i;
	if (m != -1) {
	  res = min (res, abs(m - n));
	}
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
  string word1 = "coding";
  string word2 = "practice";
  cout << s.shortestDistance(words, word1, word2) << endl;
  return 0;
}
