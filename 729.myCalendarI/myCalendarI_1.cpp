class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& e : events) {
            bool flag1 = end <= e.first;
            bool flag2 = start >= e.second;
            if (!flag1 && !flag2)
                return false;
        }
        events.push_back(make_pair(start, end));
        return true;
    }
    vector<pair<int, int> > events;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
