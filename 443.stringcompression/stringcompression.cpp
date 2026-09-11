#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int compress(vector<char>& chars) {
    int size = chars.size(), last = 0;
    int i = 0;
    while (i < size) {
      if (i == size - 1 || chars[i] != chars[i + 1])
	chars[last++] = chars[i++];
      else {
	int j = i;
	while (i < size && chars[i] == chars[j])
	  i++;
	chars[last++] = chars[j];
	string s = to_string(i - j);
	for (char c : s)
	  chars[last++] = c;
      }
    }//while
    return last;
  }
};

int main()
{
  Solution s;
  vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  vector<char> chars2 = {'a'};
  vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  cout << s.compress(chars1) << endl;
  cout << s.compress(chars2) << endl;
  cout << s.compress(chars3) << endl;
  return 0;
}
