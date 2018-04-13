class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        phoneId = maxNumbers;
        for (int i = 0; i < phoneId; i++)
            q.push(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int id = -1;
        if (!q.empty()) {
            id = q.front();
            q.pop();
            used.insert(id);
        }
        return id;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= phoneId || number < 0)
            return false;
        return !used.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used.count(number)) {
            used.erase(number);
            q.push(number);
        }
    }
    unordered_set<int> used;
    queue<int> q;
    int phoneId;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
