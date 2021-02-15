#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int numOfDup = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                numOfDup++;
            nums[i - numOfDup] = nums[i];
        }
        return nums.size() - numOfDup;
    }
};

int main()
{
    Solution s;
    int a[5] = {1,1,2,4,5};
    vector<int> vec(a, a+5);
    cout << s.removeDuplicates(vec);
    cout << endl;
    vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << "";
        ++it;
    }
    cout << endl;
    return 0;
}
