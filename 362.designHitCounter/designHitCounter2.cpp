class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        map<int, int>::iterator it = m.begin();
        while (it != m.end()) {
            if (timestamp - it->first >= 300) {
                it = m.erase(it);
            } else {
                break;
            }
        }
        m[timestamp]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (auto& p : m) {
            if (timestamp - p.first < 300)
                res += p.second;
        }
        return res;
    }
    map<int, int> m;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
