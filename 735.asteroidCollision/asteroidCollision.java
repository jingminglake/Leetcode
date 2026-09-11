class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        LinkedList<Integer> list = new LinkedList<>();
        int i = 0;
        while (i < asteroids.length) {
            if (asteroids[i] < 0) {
                boolean flag = true;
                while (!list.isEmpty() && list.getLast() > 0) {
                    if (list.getLast() < -asteroids[i]) {
                        list.pollLast();
                    } else if (list.getLast() == -asteroids[i]) {
                        list.pollLast();
                        flag = false;
                        break;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (flag) list.add(asteroids[i]);
            } else {
                list.add(asteroids[i]);
            }
            i++;
        }
        int[] res = new int[list.size()]; 
        for (int j = 0; j < list.size(); ++j) res[j] = list.get(j);
        return res;
    }
}
