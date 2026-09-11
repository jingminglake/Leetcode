class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        times.resize(300);
        hits.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int i = timestamp % 300;
        if (times[i] != timestamp) {
            hits[i] = 1;
            times[i] = timestamp;
        } else {
            hits[i]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300)
                res += hits[i];
        }
        return res;
    }
    vector<int> times, hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
