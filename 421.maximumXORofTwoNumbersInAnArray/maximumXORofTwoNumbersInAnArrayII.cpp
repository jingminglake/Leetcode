//clang++ maximumXORofTwoNumbersInAnArrayII.cpp -std=c++11
#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
    TrieNode* next[2];
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = INT_MIN;
        root = new TrieNode();
        for (int num : nums) {
            add(num);
            int max_compelement = getMaxComp(num);
            res = max (res, max_compelement);
        }
        return res;
    }
    TrieNode* root;
    void add(int num) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; i--) {
            int cur_bit = (num >> i) & 1;
            if (!cur->next[cur_bit])
                cur->next[cur_bit] = new TrieNode();
            cur = cur->next[cur_bit];
        }
    }
    int getMaxComp(int num) {
        int res = 0;
        TrieNode *cur = root;
        for (int i = 31; i >= 0; i--) {
            int cur_bit = (num >> i) & 1;
            if (cur->next[cur_bit ^ 1]) {
                res |= (1 << i);
                cur = cur->next[cur_bit ^ 1];
            } else {
                cur = cur->next[cur_bit];
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {3,10,5,25,2,8};
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}
