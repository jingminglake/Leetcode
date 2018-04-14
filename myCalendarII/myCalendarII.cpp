class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& p : overlaps) {
            if (max(p.first, start) < min(p.second, end))
                return false;
        }
        for (auto& p : events) {
            int s = max (start, p.first);
            int e = min (end, p.second);
            if (s < e)
                overlaps.emplace_back(s, e);
        }
        events.emplace_back(start, end);
        return true;
    }
    vector<pair<int, int> > events;
    vector<pair<int, int> > overlaps;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
