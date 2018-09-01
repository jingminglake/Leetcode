#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n, 0);
        int left = 0, right = n - 1;
        int index = a >= 0 ? n - 1 : 0;
        while (left <= right) {
            int leftV = f(nums[left], a, b, c);
            int rightV = f(nums[right], a, b, c);
            if (a >= 0) {
                if (leftV >= rightV) {
                    res[index--] = leftV;
                    left++;
                } else {
                    res[index--] = rightV;
                    right--;
                }
            } else {
                if (leftV <= rightV) {
                    res[index++] = leftV;
                    left++;
                } else {
                    res[index++] = rightV;
                    right--;
                }
            }
        }
        return res;
    }
    long f(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -2, 2, 4};
    int a = 1, b = 3, c = 5;
    for (int i : s.sortTransformedArray(nums, a, b, c))
        cout << i << " ";
    cout << endl;
    return 0;
}
