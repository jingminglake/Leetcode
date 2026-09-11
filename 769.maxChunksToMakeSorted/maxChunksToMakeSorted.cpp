#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxV = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxV = max (maxV, arr[i]);
            if (maxV == i)
                res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,0,2,3,4};
    cout << s.maxChunksToSorted(arr) << endl;
    return 0;
}
