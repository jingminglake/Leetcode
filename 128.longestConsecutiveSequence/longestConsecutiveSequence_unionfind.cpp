#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> lens;
    unordered_map<int, int> parent;
    int find_op(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_op(parent[node]);
    }
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if (parent.count(num))
                continue;
            else {
                parent[num] = num;
                lens[num] = 1;
            }
            if (parent.count(num - 1)) {
                int p1 = find_op(num - 1);
                int p2 = find_op(num);
                parent[p2] = p1;
                lens[p1] += lens[p2];
            }
            if (parent.count(num + 1)) {
                int p1 = find_op(num + 1);
                int p2 = find_op(num);
                parent[p1] = p2;
                lens[p2] += lens[p1];
            }
        }
        for (auto& p : lens)
            res = max (res, p.second);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {100, 4, 200, 1, 3, 2};
    cout << s.longestConsecutive(vec) << endl;
    return 0;
}
