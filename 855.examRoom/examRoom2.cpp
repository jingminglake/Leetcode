class Compare {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        int dist1 = getDist(p1);
        int dist2 = getDist(p2);
        return (dist1 < dist2) || (dist1 == dist2 && p1.first > p2.first);
    }
    int getDist(const pair<int, int>& p) const {
        int dist = 0;
        if (p.first == 0 || p.second == N - 1)
            dist = p.second - p.first;
        else
            dist = (p.second - p.first) / 2;
        return dist;
    }
    static int N;
};
int Compare::N = 0;
class ExamRoom {
public:
    int _N = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
    ExamRoom(int N) {
        _N = N;
        Compare::N = N;
        if (N > 0) pq.emplace(0, N - 1);
    }
    
    int seat() {
        int pos = -1;
        if (pq.empty())
            return pos;
        pair<int, int> p = pq.top();
        pq.pop();
        if (p.first == 0) {
            pos = 0;
        } else if (p.second == _N - 1) {
            pos = _N - 1;
        } else {
            pos = p.first + (p.second - p.first) / 2;
        }
        if (pos - p.first > 0)
            pq.emplace(p.first, pos - 1);
        if (p.second - pos > 0)
            pq.emplace(pos + 1, p.second);
        return pos;
    }
    
    void leave(int p) {
        int start = p, end = p;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> temp;
        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            if (t.second != p - 1 && t.first != p + 1) {
                temp.push(t);
                continue;
            }
            if (t.second == p - 1) {
                start = t.first;
            } else if (t.first == p + 1) {
                end = t.second;
            }
        }
        temp.emplace(start, end);
        swap(pq, temp);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
