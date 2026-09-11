class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] res = new int[nums.length];
        int[] sortNums = nums.clone();
        Arrays.sort(sortNums);
        for (int i = 0; i < nums.length; i++ ) {
            res[i] = lowerBound(sortNums, nums[i]);
        }
        return res;
    }
    
    int lowerBound(int a[], int x) { // x is the target value or key
        int l = -1, r = a.length;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[m] >= x) r = m;
            else l = m;
        }
        return r;
    }
}
