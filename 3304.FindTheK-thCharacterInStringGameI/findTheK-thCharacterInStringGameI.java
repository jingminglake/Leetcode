class Solution {
    public char kthCharacter(int k) {
        StringBuilder sb = new StringBuilder();
        sb.append('a');
       while (sb.length() < k) {
            int wordLen = sb.length();
            for (int i = 0; i < wordLen; i++) {
                char c = sb.charAt(i);
                char nextC = (char)('a' + (c - 'a' + 1) % 26);
                sb.append(nextC);
            }
        }
        return sb.charAt(k - 1);
    }
}

/*
ex k = 5
i = 0 len = 1
i = 1 len = 2
i = 2 len = 4
i = 3 len = 8 > 5; "abbcbccd" 

sb.charAt(5 - 1) = b

*/