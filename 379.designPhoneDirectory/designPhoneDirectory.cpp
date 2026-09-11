class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++)
            q.push(i);
        used = vector<bool>(maxNumbers, false);
        maxNum = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int res = -1;
        if (!q.empty()) {
            res = q.front();
            q.pop();
            used[res] = true;
        }
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= 0 && number < maxNum)
            return !used[number];
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= maxNum || !used[number])
            return;
        used[number] = false;
        q.push(number);
    }
    queue<int> q;
    vector<bool> used;
    int maxNum;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
