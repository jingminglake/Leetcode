#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n);
        for (int i = 0; i < n; i++)
            roots[i] = i;
        for (auto& edge : edges) {
            int root1 = find_op(roots, edge.first);
            int root2 = find_op(roots, edge.second);
            if (root1 != root2) {
                roots[root1] = root2;
                n--;
            }
        }
        return n;
    }
    int find_op(vector<int>& roots, int i) {
        if (roots[i] == i)
            return i;
        return roots[i] = find_op(roots, roots[i]);
    }
};

int main() {
    Solution s;
    vector<pair<int, int> > edges = {make_pair(0,1), make_pair(1,2), make_pair(3,4)};
    int N = 5;
    cout << s.countComponents(N, edges) << endl;
    return 0;
}
