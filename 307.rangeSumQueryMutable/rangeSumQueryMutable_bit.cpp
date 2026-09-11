class NumArray {
public:
    NumArray(vector<int> nums) {
        A = nums;
        size = nums.size();
        tree = vector<int>(size + 1, 0);
        for (int i = 0; i < size; i++)
            add(i, A[i]);
    }
    int lowbit(int index) {
        return index & (-index);
    }
    
    void add(int index, int val) {
        index++;
        for (int i = index; i <= size; i += lowbit(i)) {
            tree[i] += val;
        }
    }
    void update(int i, int val) {
        add(i, val - A[i]);
        A[i] = val;
    }
    int preSum(int index) {
        index++;
        int res = 0;
        for (int i = index; i > 0; i -= lowbit(i))
            res += tree[i];
        return res;
    }
    int sumRange(int i, int j) {
        return preSum(j) - preSum(i - 1);
    }
    int size;
    vector<int> tree;
    vector<int> A;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
