class Compare {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        int dist1 = getDist(p1);
        int dist2 = getDist(p2);
        return dist1 < dist2 || (dist1 == dist2 && p1.first > p2.first);
    }
    int getDist(const pair<int, int>& p) const {
        int dist = 0;
        if (p.first == -1 || p.second == N)
            dist = p.second - p.first - 1;
        else
            dist = (p.second - p.first) / 2;
        return dist;
    }
    static int N;
};
int Compare::N = 0;

class ExamRoom {
public:
    ExamRoom(int N) {
        pq.emplace(-1, N);
        _N = N;
        Compare::N = N;
    }
    int seat() {
        int seat_num = 0;
        pair<int, int> p = pq.top();
        pq.pop();
        if (p.first == -1) {
            seat_num = 0;
        } else if (p.second == _N) {
            seat_num = _N - 1;
        } else {
            seat_num = (p.first + p.second) / 2;
        }
        pq.emplace(p.first, seat_num);
        pq.emplace(seat_num, p.second);
        return seat_num;
    }
    
    void leave(int p) {
        int start = 0, end = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq_2;
        while (!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            if (t.first == p) {
                end = t.second;
            } else if (t.second == p) {
                start = t.first;
            } else {
                pq_2.push(t);
            }
        }
        pq_2.emplace(start, end);
        swap(pq, pq_2);
    }
    int _N;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
