import java.util.*;

class ValidParentheses {
    public boolean isValid(String s) {
        Map<Character, Character> m = new HashMap<>();
        m.put('(', ')');
        m.put('[', ']');
        m.put('{', '}');
        Stack<Character> stk = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == ')' || c == ']' || c == '}') {
                if (!stk.isEmpty() && m.containsKey(stk.peek()) && m.get(stk.peek()) == c) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return stk.isEmpty();
    }
	public static void main(String[] args) {
		ValidParentheses s = new ValidParentheses();
		String str = "{[]}";
		System.out.println(s.isValid(str));
	}
}
