// javac FindAnagramMappings.java
// java FindAnagramMappings

import java.util.*;
class FindAnagramMappings {
    public int[] anagramMappings(int[] A, int[] B) {
        int[] res = new int[A.length];
        Map<Integer, List<Integer> > m = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            if (!m.containsKey(B[i])) {
                m.put(B[i], new LinkedList<>());
            }
            m.get(B[i]).add(i);
        }
        for (int i = 0; i < A.length; i++) {
            res[i] = m.get(A[i]).remove(m.get(A[i]).size() - 1);
        }
        return res;
    }
	public static void main(String[] args) {
		FindAnagramMappings s = new FindAnagramMappings();
		int A[] = {12, 28, 46, 32, 50}, B[] = {50, 12, 32, 46, 28};
		int[] res = s.anagramMappings(A, B);
		for (int i : res)
			System.out.print(i + " ");
		System.out.println();
	}
}
