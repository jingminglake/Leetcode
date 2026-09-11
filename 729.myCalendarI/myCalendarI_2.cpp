class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = events.lower_bound({start, end});
        if (next != events.end() && end > next->first)
            return false;
        if (next != events.begin() && start < (--next)->second)
            return false;
        events.insert(make_pair(start, end));
        return true;
    }
    set<pair<int, int> > events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
