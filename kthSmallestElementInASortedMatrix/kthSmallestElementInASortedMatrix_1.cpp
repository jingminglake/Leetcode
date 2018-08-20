// clang++ kthSmallestElementInASortedMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) const{
            return get<0>(t1) > get<0>(t2);
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, Compare > pq;
        for (int i = 0; i < n; i++)
            pq.emplace(matrix[i][0], i, 0);
        for (int i = 0; i < k - 1; i++) {
            tuple<int, int, int> p = pq.top();
            pq.pop();
            int x = get<1>(p), y = get<2>(p);
            if (y + 1 < n) {
                pq.emplace(matrix[x][y + 1], x, y + 1);
            }
        }
        return get<0>(pq.top());
    }
    
};

int main()
{
    Solution s;
    vector<int> row1 = {1,5,9};
    vector<int> row2 = {10,11,13};
    vector<int> row3 = {12,13,15};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    cout << s.kthSmallest(matrix, 8);
    cout << endl;
    return 0;
}
