// clang++ hIndexII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 1) {
            if (citations[0] >= 1) return 1;
            else return 0;
        }
        int left = 0, right = len - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= len - mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (citations[left] >= len - left) return len - left;
        else if (citations[right] >= len - right) return len - right;
        else return 0;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {0,1,3,5,6};
    cout << s.hIndex(vec);
    cout << endl;
    return 0;
}
