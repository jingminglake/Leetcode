class Solution {
    public String alienOrder(String[] words) {
        // 1. init graph for all character, even no edge
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();

        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                graph.putIfAbsent(c, new HashSet<>());
                indegree.putIfAbsent(c, 0);
            }
        }

        // find all edges by compare adjency words, build graph
        for (int i = 0; i < words.length - 1; i++) {
            String a = words[i];
            String b = words[i + 1];
            int aLen = a.length();
            int bLen = b.length();
            int minLen = Math.min(aLen, bLen);

            int curI = 0;
            while (curI < minLen && a.charAt(curI) == b.charAt(curI)) {
                curI++;
            }
            if (curI == minLen) {
                // ex: a = "ab" b = "abc", no edge for this case
                if (aLen <= bLen) continue;
                else return ""; // a = "abc", b = "ab" is not valid order
            }
            char from = a.charAt(curI);
            char to = b.charAt(curI);
            // skip already in graph
            if (!graph.get(from).contains(to)) {
                graph.get(from).add(to);
                indegree.put(to, indegree.get(to) + 1);
            }
        }

        // 3. topo sort
        // 3.1 add all indgrees 0 nodes
        Queue<Character> q = new LinkedList<>();
        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) q.offer(c);
        }

        // 3.2 get the following nodes
        StringBuilder res = new StringBuilder();
        while (!q.isEmpty()) {
            char cur = q.poll();
            res.append(cur);

            for (char nextC : graph.get(cur)) {
                indegree.put(nextC, indegree.get(nextC) - 1);
                if (indegree.get(nextC) == 0) q.offer(nextC);
            }
        }
        // 3.3 if not visited all the nodes, there is a cycle in the graph
        if (res.length() != graph.size()) {
            return "";
        } else {
            return res.toString();
        }
    }
}