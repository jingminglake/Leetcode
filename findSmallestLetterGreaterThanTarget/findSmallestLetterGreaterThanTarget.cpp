#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int size = letters.size();
    int left = 0, right = size - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (letters[mid] > target)
	right = mid - 1;
      else
	left = mid + 1;
    }
    return letters[left % size];
  }
};

int main()
{
  Solution s;
  vector<char> ss = {'c','f','j'};
  cout << s.nextGreatestLetter(ss, 'a') << endl;
  cout << s.nextGreatestLetter(ss, 'c') << endl;
  cout << s.nextGreatestLetter(ss, 'd') << endl;
  cout << s.nextGreatestLetter(ss, 'g') << endl;
  cout << s.nextGreatestLetter(ss, 'j') << endl;
  cout << s.nextGreatestLetter(ss, 'k') << endl;
  return 0;
}
