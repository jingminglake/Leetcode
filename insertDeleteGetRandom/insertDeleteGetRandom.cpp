// clang++ insertDeleteGetRandom.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val))
            return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val))
            return false;
        int index = m[val];
        int last = nums.back();
        nums[index] = last;
        nums.pop_back();
        m[last] = index;
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    vector<int> nums;
    unordered_map<int, int> m;
};

int main()
{
    RandomizedSet s;
    s.insert(1);
    s.insert(2);
    s.remove(2);
    cout << s.getRandom() << endl;
    s.insert(2);
    cout << s.getRandom() << endl;
    return 0;
}
