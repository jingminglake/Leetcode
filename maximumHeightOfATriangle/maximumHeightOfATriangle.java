class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(maxHeightHelper(red, blue), maxHeightHelper(blue, red));
    }

    private int maxHeightHelper(int odd, int even) {
        int height = 0;
        int LineNum = 1;
        while (odd >= 0 && even >= 0) {
            if (odd - LineNum >= 0) {
                odd -= LineNum;
                height++;
                LineNum++;
            } else {
                break;
            }
            if (even - LineNum >= 0) {
                even -= LineNum;
                height++;
                LineNum++;
            } else {
                break;
            }
        }
        return height;
    }
}