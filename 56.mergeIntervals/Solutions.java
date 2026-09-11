import java.util.*;

class Solution {
	Solution() {
		String temp = new String("AaEeIiOoUu");
		vowels = new HashSet<Character>();
		for (char c : temp.toCharArray()) {
			vowels.add(c);
		}
	}
	int countVowels(String s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (vowels.contains(s.charAt(i)))
				res++;
		}
		return res;
	}
	int countVowelsRecursion(String s) {
		if (s.length() == 0) {
			return 0;
		} else {
			int t = 0;
			if (vowels.contains(s.charAt(0)))
				t = 1;
			return t + countVowelsRecursion(s.substring(1));
		}
	}
	Set<Character> vowels;
	public static void main(String args[]) {
		Solution s = new Solution();
		String str = new String("abcdfE");
		System.out.println(s.countVowels(str));
		System.out.println(s.countVowelsRecursion(str));
	}
}
