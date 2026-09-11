import java.util.*;

class PalindromePermutationII {
    public List<String> generatePalindromes(String s) {
        List<String> res = new ArrayList<>();
        Map<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            m.put(c, m.containsKey(c) ? m.get(c) + 1 : 1);
        }
        String mid = "";
        int odd = 0;
        List<Character> half = new ArrayList<>();
        for (Map.Entry<Character, Integer> entry : m.entrySet()) {
            char key = entry.getKey();
            int val = entry.getValue();
            if (val % 2 != 0) {
                mid += key;
                odd++;
            }
            for (int i = 0; i < val / 2; i++)
                half.add(key);
            if (odd > 1)
                return res;
        }
        boolean[] visited = new boolean[half.size()];
        StringBuilder path = new StringBuilder();
        genPerm(half, mid, visited, path, res);
        return res;
    }
    void genPerm(List<Character> half, String mid, boolean[] visited, StringBuilder path, List<String> res) {
        if (path.length() == half.size()) {
            res.add(path.toString() + mid + path.reverse().toString());
            path.reverse();
            return;
        }
        for (int i = 0; i < half.size(); i++) {
            if (i != 0 && half.get(i).equals(half.get(i - 1)) && !visited[i - 1])
                continue;
            if (!visited[i]) {
                path.append(half.get(i));
                visited[i] = true;
                genPerm(half, mid, visited, path, res);
                path.deleteCharAt(path.length() - 1);
                visited[i] = false;
            }
        }
    }
	public static void main(String[] args) {
		PalindromePermutationII s = new PalindromePermutationII();
		String str = "aaabb";
		for (String ss : s.generatePalindromes(str))
			System.out.print(ss + " ");
		System.out.println();
	}
}
