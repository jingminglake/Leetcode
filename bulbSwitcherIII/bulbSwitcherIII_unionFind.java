class Solution {
    public int numTimesAllBlue(int[] light) {
        int res = 0;
        groupNumber = 0;
        parent = new int[light.length];
        for (int i = 0; i < light.length; i++) {
            parent[i] = -1;
        }
        for (int li : light) {
            int index = li - 1;
            parent[index] = index ;
            groupNumber++;
            if (index - 1 >= 0 && parent[index - 1] != -1) {
                unionOp(index, index - 1);
                groupNumber--;
            }
            if (index + 1 < light.length && parent[index + 1] != -1) {
                unionOp(index, index + 1);
                groupNumber--;
            }
            if (groupNumber == 1 && findOp(index) == 0) {
                res++;
            }
        }
        return res;
    }
    
    private int findOp(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = findOp(parent[i]);
    }
    
    private void unionOp(int a, int b) {
        int pa = findOp(a);
        int pb = findOp(b);
        if (pa < pb) {
            parent[pb] = pa;
        } else if (pa > pb) {
            parent[pa] = pb;
        }
    }
    
    private int[] parent;
    private int groupNumber;
}