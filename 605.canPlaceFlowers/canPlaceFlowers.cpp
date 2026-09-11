#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) 
                && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;
    }
};

int main()
{
    Solution s;
    int a[8] = {0,1,0,1,0,1,0,0};
    vector<int> vec(a,a+8);
    cout << s.canPlaceFlowers(vec, 2) << endl;
    return 0;
}
