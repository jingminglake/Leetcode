class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        // build email connection component graph
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, String> emailToName = new HashMap<>();

        for (List<String> account : accounts) {
            String name = account.get(0);
            String firstEmail = account.get(1);
            for (int i = 1; i < account.size(); i++) {
                String email = account.get(i);
                // connect to the first email(bi direction), should have first email when just one email
                graph.computeIfAbsent(account.get(i), x -> new ArrayList<String>());
                if (i > 1) {
                    graph.get(firstEmail).add(email);
                    graph.get(email).add(firstEmail);
                }
                emailToName.put(account.get(i), name);
            }
        }

        // bfs fooldfill
        List<List<String>> res = new ArrayList<>();
        Set<String> visited = new HashSet<>();
        for (String email : graph.keySet()) {
            if (visited.contains(email)) continue;
            List<String> component = new ArrayList<>();

            Queue<String> q = new LinkedList<>();
            visited.add(email);
            q.add(email);

            while (!q.isEmpty()) {
                String peek = q.poll();
                component.add(peek);
                for (String neighbor : graph.get(peek)) {
                    if (!visited.contains(neighbor)) {
                        visited.add(neighbor);
                        q.add(neighbor);
                    }
                }
            }
            Collections.sort(component);
            List<String> mergedAccount = new ArrayList<>();
            mergedAccount.add(emailToName.get(email));
            mergedAccount.addAll(component);
            res.add(mergedAccount);
        }

        return res;
    }
}