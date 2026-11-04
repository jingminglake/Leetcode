class Solution {
    public int minSteps(String s, String t) {
        int[] needCnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            needCnt[c - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            needCnt[c - 'a']--;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (needCnt[i] > 0) res += needCnt[i];
        }
        return res;
    }
}

/*
s = "bab", t = "aba" 

for s => needCnt : {a: 1, b : 2, c:0, ...}
for t => needCnt : {a: -1 b: 1, c:0, ...}

res = 1


s = "leetcode", t = "practice"
for s => needCnt : {c: 1, d: 1, e: 3, l: 1, o: 1, t: 1, }
for t => needCnt : {p: -1, r: -1, a: -1, c: -1, t: 0, i: -1, e: 2, d: 1, l: 1, o: 1}

res = 2 + 1 + 1 + 1 = 5

*/