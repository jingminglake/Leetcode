#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
        srand(time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = nums_;
        for (int i = 0; i < res.size(); i++) {
            int p = rand() % (res.size() - i);
            swap(res[i + p], res[i]);
        }
        return res;
    }
    vector<int> nums_;
};

int main() {
    vector<int> nums;
    for (int i = 0; i < 52; i++)
        nums.push_back(i);
    for (int n : nums)
        cout << n << " ";
    cout << endl;
    Solution s(nums);
    vector<int> nums1 = s.shuffle();
    cout << "after shuffle: " << endl;
    for (int n : nums1)
        cout << n << " ";
    cout << endl;
    return 0;
}
