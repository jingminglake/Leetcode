class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        len = size;
        sum = 0.0;
        lastIndex = 0;
        vec.reserve(10);
    }
    
    double next(int val) {
        if (vec.size() >= len) {
           sum -= vec[lastIndex++]; 
        }
        sum += val;
        vec.push_back(val);
        int l = vec.size() < len ? vec.size() : len;
        return sum / l;
    }
    double sum;
    int len;
    int lastIndex;
    vector<int> vec;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
