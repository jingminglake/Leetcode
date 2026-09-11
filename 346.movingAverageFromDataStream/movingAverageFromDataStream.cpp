class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        len = size;
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > len) {
            sum -= q.front();
            q.pop();
        }
        return sum * 1.0 / q.size();
    }
    queue<int> q;
    int sum;
    int len;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
