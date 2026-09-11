class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        cur = vec2d.begin();
        end = vec2d.end();
        i = 0;
    }

    int next() {
        int res = -1;
        if (hasNext()) {
            res = (*cur)[i];
            i++;
        }
        return res;
    }

    bool hasNext() {
        while (cur != end && i == cur->size()) {
            cur++;
            i = 0;
        }
        return cur != end;
    }
    vector<vector<int> >::iterator cur, end;
    int i;
};
