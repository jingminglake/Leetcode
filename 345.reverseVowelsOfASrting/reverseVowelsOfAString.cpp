#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        vector<char> vec = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> vowels(vec.begin(), vec.end());
        while (left < right) {
            while (left < right && !vowels.count(s[left]))
                left++;
            while (left < right && !vowels.count(s[right]))
                right--;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main()
{
  Solution s;
  string str = "aA";
  cout << s.reverseVowels(str) << endl;
  return 0;
}
