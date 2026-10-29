class Solution {
    public String minWindow(String s, String t) {
        int lenS = s.length();
        int lenT = t.length();
        int res = lenS + 1;
        int resStartIndex = 0;

        int uniCharNumExpected = 0;
        int[] charNumExpected = new int[128];
        for (int i = 0; i < lenT; i++) {
            char c = t.charAt(i);
            charNumExpected[c]++;
            if (charNumExpected[c] == 1) uniCharNumExpected++;
        }

        int uniChar = 0;
        int[] charNum = new int[128];
        int left = 0;
        // for each window right, there is a candiate for res
        for (int right = 0; right < lenS; right++) {
            // add right
            char rightC = s.charAt(right);
            charNum[rightC]++;
            if (charNum[rightC] == charNumExpected[rightC]) uniChar++;

            // move left until window is not valid
            while (uniChar == uniCharNumExpected) {
                // calculate res when window is valid
                if (right - left + 1 < res) { // get minimum
                    res = right - left + 1;
                    resStartIndex = left;
                }
                
                char leftC = s.charAt(left);
                charNum[leftC]--;
                // first time not match the expected num
                if (charNum[leftC] == charNumExpected[leftC] - 1) uniChar--;
                left++;
            }
        }
        if (res < lenS + 1) return s.substring(resStartIndex, resStartIndex + res);
        else return "";
    }
    /*

    ex1: s = "aab", t = "ab" 
    cExp= {a:1, b:1} uniExp= 2

    right = 0, rightC = 'a', a:1, uni=1, while 1=2 false, res = 4, start = 0
    right = 1, rightC = 'a', {a : 2}, uni = 1 while 1=2 false, res = 4, start = 0
    right = 2, rightC = 'b', {a:2, b: 1}, uni = 2, while 2=2 true, res = 2 - 0 + 1 = 3, start = 0
                                                   left = 1, {a:1, b: 1} res = 2, start = 1
                                                   left = 2, {a:0, b: 1}, while 1 != 2 false
    right = 3 --> end res = 2, start = 1 if 2 < 4 true return s.substring(1, 1 + 2) = "ab"

    ex2: s = "a", t = "b"
    cExp = {b:1}, uniExp=1, res = 2

    right=0, rightC = 'a', {a : 1} uni = 0 while 0 == 1 false res = 2, start = 0
    right=1, --> end res = 2, start = 0, if 2 < 2 false return ""

    ex3: s="ab"，t="ab"
    cExp = {a : 1, b: 1}, uniExp = 2, res = 3

    right = 0, rightC = 'a', {a : 1}, uni=1, while 1==2 false, res = 3, start = 0
    right = 1, rightC = 'b', {a:1, b:1}m uni=2 while 2==2 true res = 1-0+1 = 2, start = 0
                                                left = 1, {a: 0, b: 1}, res = 2, start = 0
    right = 2, --> end res = 2, start = 0, if 2 < 3 return s.subtring(0, 0 + 2) = ab

    */
}