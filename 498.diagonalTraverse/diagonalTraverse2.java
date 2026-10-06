class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        List<List<Integer>> groups = new ArrayList<>();
        for (int i = 0; i <= m + n - 2; i++) groups.add(new ArrayList<>());
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                groups.get(r + c).add(mat[r][c]);
            }
        }
        int[] res = new int[m * n];
        int index = 0;
        for (int i = 0; i <= m + n - 2; i++) {
            List<Integer> group = groups.get(i);
            if (i % 2 == 0) {
                for (int j = group.size() - 1; j >= 0; j--) res[index++] = group.get(j);
            } else {
                for (Integer e : group) res[index++] = e;
            }
        }
        return res;
    }
}