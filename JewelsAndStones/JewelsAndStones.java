import java.util.*;
public class JewelsAndStones {
	public int numJewelsInStones(String J, String S) {
        int res = 0;
        Set s = new HashSet();
        for (char c : J.toCharArray())
            s.add(c);
        for (char c : S.toCharArray()) {
            if (s.contains(c))
                res++;
        }
        return res;
    }
	public static void main(String[] args) {
		String J = new String("aA");
		String S = new String("aAAbbb");
		JewelsAndStones s = new JewelsAndStones();
		System.out.println(s.numJewelsInStones(J, S));
	}

}
