#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 && p2 >= 0) {
            int n1 = nums1[p1];
            int n2 = nums2[p2];
            if (n1 > n2) {
                nums1[p--] = n1;
                p1--;
            } else {
                nums1[p--] = n2;
                p2--;
            }
        }
        while (p2 >= 0) {
            nums1[p--] = nums2[p2--];
        }
    }
};

int main()
{
    Solution s;
    int a[10] = {2,4,8,10,15,0,0,0,0,0};
    int b[5] = {3,4,6,8,11};
    vector<int> vec1(a, a+10);
    vector<int> vec2(b, b+5);
    s.merge(vec1, 5, vec2, 5);
    vector<int>::iterator it = vec1.begin();
    while (it != vec1.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
 
    return 0;
}
