// clang++ trappingRainWater.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height) {
        int res = 0;
        int size = height.size();
        if (size == 0)
            return 0;
        int left = 0;
        int right = size - 1;
        int leftMax = 0, maxRight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax)
                    leftMax = height[left];
                else
                    res += leftMax - height[left];
                left++;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    res += maxRight - height[right];
                right--;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height) << endl;;
    return 0;
}
