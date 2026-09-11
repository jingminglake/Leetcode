import java.util.*;

class PalindromePermutation {
    public boolean canPermutePalindrome(String s) {
        Set<Character> charSet = new HashSet<Character>();
        for (char c : s.toCharArray()) {
            if (!charSet.contains(c))
                charSet.add(c);
            else
                charSet.remove(c);
        }
        return charSet.size() <= 1;
    }
	public static void main(String[] args) {
		PalindromePermutation s = new PalindromePermutation();
		String str = "code";
		System.out.println(s.canPermutePalindrome(str));
	}
}
