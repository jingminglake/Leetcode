#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(), 0);
        if (A.size() != B.size() || A.size() == 0)
            return res;
        unordered_map<int, vector<int> > m;
        for (int i = 0; i < B.size(); i++) {
            m[B[i]].push_back(i);
        }
        for (int i = 0; i < A.size(); i++) {
            res[i] = m[A[i]].back();
            m[A[i]].pop_back();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A = {12, 28, 46, 32, 50}, B = {50, 12, 32, 46, 28};
    for (int i : s.anagramMappings(A, B))
        cout << i << " ";
    cout << endl;
    return 0;
}
