class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int ongoing = 0, res = 0;
        for (auto& p : timeline) {
            res = max (res, ongoing += p.second);
        }
        return res;
    }
    map<int, int> timeline;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
