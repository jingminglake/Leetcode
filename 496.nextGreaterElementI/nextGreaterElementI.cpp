#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        stack<int> s;
        for (int n : nums) {
            while (!s.empty() && n > s.top()) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        for (int n : findNums) {
            if (m.count(n))
                res.push_back(m[n]);
            else
                res.push_back(-1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[3] = {4,1,2};
    int b[4] = {1,3,4,2};
    vector<int> vec1(a, a+3);
    vector<int> vec2(b, b+4);
    vector<int> res = s.nextGreaterElement(vec1, vec2);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
