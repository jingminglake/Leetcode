class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        m.put('I', 1);
        m.put('V', 5);
        m.put('X', 10);
        m.put('L', 50);
        m.put('C', 100);
        m.put('D', 500);
        m.put('M', 1000);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            Character c1 = s.charAt(i);
            if (i != s.length() - 1) {
                Character c2 = s.charAt(i + 1);
                if (m.get(c2) <= m.get(c1)) {
                  res += m.get(c1);
                } else {
                    res += m.get(c2) - m.get(c1);
                    i++;
                }
            } else {
                 res += m.get(c1);
            }
            
        }
        return res;
    }
}
