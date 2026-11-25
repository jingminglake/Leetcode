class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1, j = t.length() - 1;
        while (true) {
            i = nextValid(s, i);
            j = nextValid(t, j);
            if (i < 0 && j < 0) return true;
            if (i < 0 || j < 0) return false;
            if (s.charAt(i) != t.charAt(j)) return false;
            i--;
            j--;
        }
    }

    private int nextValid(String s, int i) {
        int skip = 0;
        while (i >= 0) {
            if (s.charAt(i) == '#') {
                skip++;
                i--;
            } else if (skip > 0) {
                skip--;
                i--;
            } else {
                break;
            }
        }
        return i;
    }
}