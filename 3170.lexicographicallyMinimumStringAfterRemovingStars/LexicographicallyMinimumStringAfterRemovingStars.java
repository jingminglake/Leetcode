class Solution {
    public String clearStars(String s) {
        Stack<Integer>[] charStack = new Stack[26];
        for (int i = 0; i < 26; i++) {
            charStack[i] = new Stack<>();
        }
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.length() && s.charAt(i) != '*') {
                charStack[s.charAt(i) - 'a'].push(i);
                count++;
                i++;
            }

            if (i == s.length()) {
                break;
            } else {
                if (count > 0) {
                    clearHelper(charStack);
                    count--;
                }
            }
        }

        Set<Integer> remainIndexes = new HashSet<Integer>();

        for (int i = 0; i < 26; i++) {
            while (!charStack[i].isEmpty()) {
                remainIndexes.add(charStack[i].pop());
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (remainIndexes.contains(i)) sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    private void clearHelper(Stack<Integer>[] charStack) {
        for (int i = 0; i < 26; i++) {
            if (!charStack[i].isEmpty()) {
                charStack[i].pop();
                break;
            }
        }
    }
}