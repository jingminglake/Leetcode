#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) pq.pop();
        return pq.top();
    }
    
    priority_queue<int, vector<int>, greater<int> > pq;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    vector<int> arr = {4,5,8,2};
    int k = 3;
    KthLargest kthLargest(3, arr);
    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;
    return 0;
}
