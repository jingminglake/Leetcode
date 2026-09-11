// clang++ kthLargestElementInAnArray_2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Solution s;
    vector<int> vec = {3,2,1,5,6,4}; 
    cout << s.findKthLargest(vec, 2);
    cout << endl;
    return 0;
}
