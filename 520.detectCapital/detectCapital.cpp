#include <iostream>
using namespace std;

class Solution{
public:
  bool checkRecord(string word) {
    int size = word.length();
    if (size <= 1)
      return true;
    char firstC = word[0];
    char secondC = word[1];
    if (isupper(firstC)) {
      if (isupper(secondC)) {
	int i = 2;
	while (i < size) {
	  if (!isupper(word[i]))
	    return false;
	  i++;
        }
      } else {
	int i = 2;
	while (i < size) {
	  if (isupper(word[i]))
	    return false;
	  i++;
        }
      }
    } else {
      int i = 1;
      while (i < size) {
	if (isupper(word[i]))
	  return false;
	i++;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  string str = "aa";
  cout << s.checkRecord(str) << endl;
  return 0;
}
