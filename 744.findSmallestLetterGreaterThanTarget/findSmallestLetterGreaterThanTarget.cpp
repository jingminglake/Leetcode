#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (letters[left] > target) return letters[left];
        else if (letters[right] > target) return letters[right];
        else return letters[0];
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
