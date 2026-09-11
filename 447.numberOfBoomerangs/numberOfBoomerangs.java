class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        int pNumber = points.length;
        Map<Integer, Integer> map = new HashMap<>(); // distince -> number
        for (int i = 0; i < pNumber; i++) {
            for (int j = 0; j < pNumber; j++) {
                if (i == j) continue;
                int d = getDistance(points[i], points[j]);
                map.put(d, map.getOrDefault(d, 0) + 1);
            }
            for (int val : map.values()) {
                res += val * (val - 1);
            }
            map.clear();
        }
        return res;
    }
    
    public int getDistance(int[] p1, int[] p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
}
