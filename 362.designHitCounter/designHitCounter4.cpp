class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (m.count(timestamp % 300)) {
            if (m[timestamp % 300].first != timestamp) {
                m[timestamp % 300].first = timestamp;
                m[timestamp % 300].second = 1;
            } else {
                m[timestamp % 300].second++;
            }
        } else {
            m[timestamp % 300].first = timestamp;
            m[timestamp % 300].second = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (auto& p : m) {
            if (timestamp - p.second.first < 300)
                res += p.second.second;
        }
        return res;
    }
    unordered_map<int, pair<int, int> > m;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
