class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int len = s.length();
        int[] shiftsNum = new int[len]; // (3+5+9) % 26, (5+9) % 26, 9 % 26
        shiftsNum[len - 1] = shifts[len - 1] % 26; 
        for (int i = len - 2; i >= 0; i--) {
            shiftsNum[i] = (shiftsNum[i + 1] + shifts[i]) % 26;
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            char shiftC = (char)('a' + (c - 'a' + shiftsNum[i]) % 26);
            sb.append(shiftC);
        }
        return sb.toString();
    }
}

/*
ex. s = "abc", shifts = [3,5,9]
len = 3

shiftNum = {0, 0, 0}
len - 1 == 2 => shiftNum = {0, 0, 9}
i = len- 2 = 1 => shiftNum = {0, 5+9, 9}
i = 0 => shiftNum = {3 + 5 + 9, 5+9, 9}

"abcdefghijklmnopqrstuvwxyz"

sb = ""
i = 0, 'a' + ('a' - 'a' + 17) % 26 = 'r'
i = 1, 'a' + ('b'- 'a' + 14) % 26 = 'p'
i = 2, 'a' + ('c' - 'a' + 9) % 26 = 'l'

return "rpl"

ex2. s = "z", shifts = "int_max"
shiftNum = int_max % 26 = 23

i = 0, 'a' + ('z' - 'a' + 23) % 26 = 'a' + 22 = 'u'
*/