#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size() == 0 || heaters.size() == 0)
            return 0;
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); i++) {
            res = max(res, binarySearch(heaters, houses[i]) );
        }
        return res;
    }
    int binarySearch(vector<int>& heaters, int target) {
        int left = 0, right = heaters.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] > target)
                right = mid;
            else if (heaters[mid] < target)
                left = mid;
            else
                return 0;
        }
        if (abs(heaters[left] - target) < abs(heaters[right] - target))
            return abs(heaters[left] - target);
        else
            return abs(heaters[right] - target);
    }
};

int main()
{
  Solution s;
  int a[8] = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
  int b[10] = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
  vector<int> vec1(a, a+8);
  vector<int> vec2(b, b+10);
  cout << s.findRadius(vec1, vec2) << endl;
  return 0;
}
