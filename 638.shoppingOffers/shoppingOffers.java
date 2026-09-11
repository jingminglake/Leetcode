class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return dfs(price, special, needs, 0);
    }
    
    public int dfs(List<Integer> price, List<List<Integer>> special, List<Integer> needs, int start) {
        int res =  purchaseWithOriginalPrice(price, needs);
        for (int i = start; i < special.size(); i++) {
            List<Integer> offer = special.get(i);
            List<Integer> temp = new ArrayList<>();
            for (int j = 0; j < needs.size(); j++) {
                if (needs.get(j) < offer.get(j)) { // check if able to buy one offer
                    temp = null;
                    break;
                }
                temp.add(needs.get(j) - offer.get(j)); // buy j
            }
            if (temp != null) { // can buy one offer
                res = Math.min(res, offer.get(offer.size() - 1) + dfs(price, special, temp, i));
            }
        }
        return res;
    }
    
    public int purchaseWithOriginalPrice(List<Integer> price, List<Integer> needs) {
        int total = 0;
        for (int i = 0; i < needs.size(); i++) {
            total += price.get(i) * needs.get(i);
        }
        return total;
    }
}