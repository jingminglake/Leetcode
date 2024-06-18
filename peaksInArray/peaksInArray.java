class Solution {
    public List<Integer> countOfPeaks(int[] nums, int[][] queries) {
        List<Integer> res = new ArrayList<>();
        int[] segmentTree = new int[4 * nums.length];
        int[] peak = new int[nums.length];
        for (int i = 1; i < peak.length - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak[i] = 1;
            }
        }
        //for (int p : peak) System.out.println(p);
        buildTree(segmentTree, peak, 0, peak.length - 1, 0);

        for (int i = 0; i < queries.length; i++) {
            if (queries[i][0] == 2) {
                int index = queries[i][1];
                nums[index] = queries[i][2];
                // update index - 1
                int index_pre = index - 1;
                if (index_pre - 1 >= 0) {
                    if (nums[index_pre] > nums[index_pre - 1] && nums[index_pre] > nums[index]) {
                        if (peak[index_pre] == 0) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_pre, 1);
                            peak[index_pre] = 1;
                        }
                    } else if (nums[index_pre] < nums[index_pre - 1] && nums[index_pre] < nums[index]) {
                        if (peak[index_pre] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_pre, 0);
                            peak[index_pre] = 0;
                        }
                    } else {
                        if (peak[index_pre] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_pre, 0);
                            peak[index_pre] = 0;
                        }
                    }
                }
                // update index + 1
                int index_post = index + 1;
                if (index_post + 1 < nums.length) {
                    if (nums[index_post] > nums[index_post + 1] && nums[index_post] > nums[index]) {
                        if (peak[index_post] == 0) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_post, 1);
                            peak[index_post] = 1;
                        }
                    } else if (nums[index_post] < nums[index_post + 1] && nums[index_post] < nums[index]) {
                        if (peak[index_post] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_post, 0);
                            peak[index_post] = 0;
                        }
                    } else {
                        if (peak[index_post] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index_post, 0);
                            peak[index_post] = 0;
                        }
                    }
                }
                // update index
                if (index - 1 >= 0 && index + 1 < nums.length) {
                    if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]) {
                        if (peak[index] == 0) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index, 1);
                            peak[index] = 1;
                        }
                    } else if (nums[index] < nums[index - 1] && nums[index] < nums[index + 1]) {
                        if (peak[index] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index, 0);
                            peak[index] = 0;
                        }
                    } else {
                        if (peak[index] == 1) {
                            updateTree(segmentTree, peak, 0, nums.length - 1, 0, index, 0);
                            peak[index] = 0;
                        }
                    }
                }
                //for (int p : peak) System.out.println(p);
            } else if (queries[i][0] == 1) {
                // +1 -1 due to The first and the last element of a subarray also cannot be a peak.
                res.add(queryTree(segmentTree, peak, 0, nums.length - 1, 0, queries[i][1] + 1, queries[i][2] - 1));
            }
        }
        return res;
    }
    private void buildTree(int[] segmentTree, int[] peak, int start, int end, int node) {
        if (start == end) {
            segmentTree[node] = peak[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftNode  = node * 2 + 1;
            int rightNode = node * 2 + 2;
            buildTree(segmentTree, peak, start, mid, leftNode);
            buildTree(segmentTree, peak, mid + 1, end, rightNode);
            segmentTree[node] = segmentTree[leftNode] + segmentTree[rightNode];
        }
    }

    private void updateTree(int[] segmentTree, int[] peak, int start, int end, int node, int index, int val) {
        if (start == end) {
            segmentTree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftNode  = node * 2 + 1;
            int rightNode = node * 2 + 2;
            if (index <= mid) {
                updateTree(segmentTree, peak, start, mid, leftNode, index, val);
            } else {
                updateTree(segmentTree, peak, mid + 1, end, rightNode, index, val);
            }
            segmentTree[node] = segmentTree[leftNode] + segmentTree[rightNode];
        }
    }

    private int queryTree(int[] segmentTree, int[] peak, int start, int end, int node, int l, int r) {
        if (r < start || l > end) {
            return 0;
        } else if (l <= start && r >= end) {
            return segmentTree[node];
        } else if (start == end) {
            return segmentTree[start];
        }
        int mid = start + (end - start) / 2;
        int leftNode  = node * 2 + 1;
        int rightNode = node * 2 + 2;
        int leftRes = queryTree(segmentTree, peak, start, mid, leftNode, l, r);
        int rightRes = queryTree(segmentTree, peak, mid + 1, end, rightNode, l, r);
        return leftRes + rightRes;
    }
}