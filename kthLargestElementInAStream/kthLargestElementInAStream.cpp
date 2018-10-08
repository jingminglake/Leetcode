#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        _k = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k)
            pq.pop();
        return pq.top();
    }
    int _k;
    priority_queue<int, vector<int>, greater<int> > pq;
};

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
