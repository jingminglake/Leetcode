class Solution {
    public String convert(String s, int numRows) {
        StringBuilder[] sb = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) sb[i] = new StringBuilder();
        char[] arr = s.toCharArray();
        int i = 0;
        while (i < arr.length) {
            for (int j = 0; j < numRows && i < arr.length; j++)
                sb[j].append(arr[i++]);
            for (int j = numRows - 2; j >= 1 && i < arr.length; j--)
                sb[j].append(arr[i++]);
        }
        for (i = 1; i < sb.length; i++)
            sb[0].append(sb[i]);
        return sb[0].toString();
    }
}
