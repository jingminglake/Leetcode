class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int accountsCount = accounts.size();
        UnionFind uf = new UnionFind(accountsCount);

         // 邮箱第一次出现在哪个账户中
        Map<String, Integer> emailToAccount = new HashMap<>();
        // 第一阶段：合并共享邮箱的账户
        for (int accountId = 0;
             accountId < accountsCount;
             accountId++) {

            List<String> account = accounts.get(accountId);

            for (int i = 1; i < account.size(); i++) {
                String email = account.get(i);

                Integer previousAccount =
                    emailToAccount.putIfAbsent(email, accountId);

                // 邮箱以前出现过，合并两个账户
                if (previousAccount != null) {
                    uf.union(accountId, previousAccount);
                }
            }
        }

        // 第二阶段：按照最终根节点收集邮箱
        Map<Integer, List<String>> rootToEmails = new HashMap<>();

        for (Map.Entry<String, Integer> entry
                : emailToAccount.entrySet()) {

            String email = entry.getKey();
            int accountId = entry.getValue();

            int root = uf.find(accountId);

            rootToEmails
                .computeIfAbsent(root, key -> new ArrayList<>())
                .add(email);
        }

        // 第三阶段：排序邮箱并加入姓名
        List<List<String>> result = new ArrayList<>();

        for (Map.Entry<Integer, List<String>> entry
                : rootToEmails.entrySet()) {

            int root = entry.getKey();
            List<String> emails = entry.getValue();

            Collections.sort(emails);

            List<String> mergedAccount =
                new ArrayList<>(emails.size() + 1);

            // 同一个集合中的账户姓名一定相同
            mergedAccount.add(accounts.get(root).get(0));
            mergedAccount.addAll(emails);

            result.add(mergedAccount);
        }

        return result;


    }

    private static class UnionFind {

        private final int[] parent;
        private final int[] rank;

        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];

            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        int find(int node) {
            if (parent[node] != node) {
                // 路径压缩
                parent[node] = find(parent[node]);
            }

            return parent[node];
        }

        void union(int first, int second) {
            int rootFirst = find(first);
            int rootSecond = find(second);

            if (rootFirst == rootSecond) {
                return;
            }

            // 按秩合并
            if (rank[rootFirst] < rank[rootSecond]) {
                parent[rootFirst] = rootSecond;
            } else if (rank[rootFirst] > rank[rootSecond]) {
                parent[rootSecond] = rootFirst;
            } else {
                parent[rootSecond] = rootFirst;
                rank[rootFirst]++;
            }
        }
    }
}