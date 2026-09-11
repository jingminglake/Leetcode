class Solution {
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;
        int[] segmentTree = new int[4 * n];
        buildTree(segmentTree, nums, 0, 0, n - 1);

        int left = 0, right = 0;
        int v = nums[0];
        int res = Math.abs(v - k);
        while (right < n) {
            //v = getAnd(nums, left, right);
            v = queryTree(segmentTree, 0, 0, n - 1, left, right);

            //System.out.println(v + ": " + left + " " + right);
            while (left <= right && v < k) {
                //v = getAnd(nums, left, right);
                v = queryTree(segmentTree, 0, 0, n - 1, left, right);
                //System.out.println(v + ":: " + left + " " + right);
                res = Math.min(res, Math.abs(v - k));
                left++;
            }
            if (left > right) left--;
            res = Math.min(res, Math.abs(v - k));
            right++;
        }
        return res;
    }

    private int getAnd(int[] nums, int start, int end) {
        int res = nums[start];
        for (int i = start + 1; i <= end; i++)
            res &= nums[i];
        return res;
    }

    private void buildTree(int[] segmentTree, int[] nums, int node, int start, int end) {
        if (start == end) {
            segmentTree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;
            buildTree(segmentTree, nums, leftNode, start, mid);
            buildTree(segmentTree, nums, rightNode, mid + 1, end);
            segmentTree[node] = segmentTree[leftNode] & segmentTree[rightNode];
        }
    }

    private void updateTree(int[] segmentTree, int[] nums, int node, int start, int end, int idx, int val) {
        if (start == end) {
            nums[idx] = val;
            segmentTree[node] = val;
        }
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        if (idx >= start && idx <= mid) {
            updateTree(segmentTree, nums, leftNode, start, mid, idx, val);
        } else {
            updateTree(segmentTree, nums, rightNode, mid + 1, end, idx, val);
        }
        segmentTree[node] = segmentTree[leftNode] & segmentTree[rightNode];
    }

    private int queryTree(int[] segmentTree, int node, int start, int end, int L, int R) {
        if (R < start || L > end) {
            return ~0;
        } else if (L <= start && R >= end) {
            return segmentTree[node];
        } else if (start == end) {
            return segmentTree[start];
        }
        int mid = start + (end - start) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        int leftRes = queryTree(segmentTree, leftNode, start, mid, L, R);
        int rightRes = queryTree(segmentTree, rightNode, mid + 1, end, L, R);
        return leftRes & rightRes;
    }
}