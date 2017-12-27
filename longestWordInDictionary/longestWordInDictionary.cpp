#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> built;
    string res;
    for (string w : words) {
      if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
	res = w.size() > res.size() ? w : res;
	built.insert(w);
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> words = {"a","banana", "app", "appl", "ap", "apply", "apple"};
  cout << s.longestWord(words) << endl;
  return 0;
}
