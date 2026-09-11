// clang++ slidingWindowMedian.cpp -std=c++11

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res(n - k + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                // remove at first
                if (leftS.count(nums[i - k]))
                    leftS.erase(leftS.find(nums[i - k]));
                else
                    rightS.erase(rightS.find(nums[i - k]));
                // adjust to properity
                if (leftS.size() - rightS.size() == 2) {
                    rightS.insert(*leftS.rbegin());
                    leftS.erase(--leftS.end());
                } else if (leftS.size() + 1 == rightS.size()) {
                    leftS.insert(*rightS.begin());
                    rightS.erase(rightS.begin());
                }
            }
            // add
            addNum(nums[i]);
            // getMedian
            if (i + 1 >= k)
                res[i - k + 1] = getMedian();
        }
        return res;
    }
    void addNum(int num) {
        leftS.insert(num);
        rightS.insert(*leftS.rbegin());
        leftS.erase(--leftS.end());
        if (leftS.size() < rightS.size()) {
            leftS.insert(*rightS.begin());
            rightS.erase(rightS.begin());
        }
    }
    double getMedian() {
        if (leftS.empty())
            return -1.0;
        if (leftS.size() > rightS.size())
            return *leftS.rbegin();
        else
            return ((double)*leftS.rbegin() + *rightS.begin()) / 2.0;
    }
    multiset<int> leftS, rightS;
};

int main()
{
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<double> vec = s.medianSlidingWindow(nums, 3);
    for (double d : vec)
        cout << d << " ";
    cout << endl;
    return 0;
}
