#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        count = n;
        for (auto& e : edges) {
            int p1 = find_op(e.first);
            int p2 = find_op(e.second);
            if (p1 != p2) {
                parent[p1] = p2;
                count--;
            } else 
                return false;
        }
        return count == 1;
    }
    int find_op(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_op(parent[node]);
    }
    int count;
    vector<int> parent;
};

int main()
{
    Solution s;
    vector<pair<int, int> > edges = {{0,1},
                                     {0,2},
                                     {0,3},
                                     {1,4}};
    cout <<  s.validTree(5, edges) << endl;
    return 0;
}
