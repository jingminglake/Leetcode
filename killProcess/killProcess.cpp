class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int size = pid.size();
        unordered_map<int, vector<int> > children;
        for (int i = 0; i < size; i++) {
            if (!children.count(ppid[i])) {
                children.insert({ppid[i], vector<int>()});
            }
            children[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        killByPid(res, kill, children);
        return res;
    }
    void killByPid(vector<int>& res, int pid, unordered_map<int, vector<int> >& children) {
        if (!children.count(pid)) {
            res.push_back(pid);
            return;
        }
        res.push_back(pid);
        for (int id : children[pid]) {
            killByPid(res, id, children);
        }
    }
};
