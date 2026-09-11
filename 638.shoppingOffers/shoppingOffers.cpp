#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs, 0);
    }
    int dfs(vector<int>& price, vector<vector<int> >& special, vector<int> needs, int index) {
        if (index == special.size()) {
            return purchaseWithOrginalPrice(price, needs);
        }
        vector<int> nextNeeds = needs;
        int i;
        for (i = 0; i < price.size(); i++) {   // try to buy special[index]
            int remain = needs[i] - special[index][i];
            if (remain < 0) // can not buy
                break;
            else
                nextNeeds[i] = remain;
        }
        if (i == price.size()) // can buy one special[index]
            return min (special[index][i] + dfs(price, special, nextNeeds, index),
                       dfs(price, special, needs, index + 1));
        else
            return dfs(price, special, needs, index + 1);
    }
    int purchaseWithOrginalPrice(vector<int>& price, vector<int>& needs) {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += needs[i] * price[i];
        }
        return sum;
    }
};

int main() {
  Solution s;
  vector<int> price = {2,3,4};
  vector<vector<int> > special = {{1,1,0,4}, {2,2,1,9}};
  vector<int> needs = {1,2,1};
  cout << s.shoppingOffers(price, special, needs) << endl;
  return 0;
}
