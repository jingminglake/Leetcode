class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        // {postion, speed}
        List<int[]> cars = new ArrayList<>();
        for (int i = 0; i < position.length; i++) {
            cars.add(new int[]{position[i], speed[i]});
        }
        // sort by postion descend
        Collections.sort(cars, (a, b) -> Integer.compare(b[0], a[0]));

        int res = 0;
        double prevFleetTime = 0.0; // latest fleet arriving time
        for (int i = 0; i < position.length; i++) {
            int p = cars.get(i)[0];
            int s = cars.get(i)[1];
            double curCarTime = (target * 1.0 - p) / s;
            if (curCarTime > prevFleetTime) {
                // can not catch the fleet ahead
                // add a new fleet
                res++;
                prevFleetTime = curCarTime;
            } 
            //else
            // can catch the fleet ahead
            // add current car into the fleet

        }
        return res;
    }

    /*
    ex1: p = [3], speed = 3, target = 10
    prevTime = 0.0
    i = 0: curTime = 3.3 > prevTime, res = 1, prevTime = 3.3
    return 1

    ex2: position: [4, 2, 0], speed: [1, 2, 4], target = 100
    prevTime = 0.0
    i = 0: curTime = 96 > 0.0 res = 1, prevTime = 96
    i = 1: curTime = 98/2 = 49 < prevTime, res = 1
    i = 2: curTime = 100/4 = 25 < prevTime, res = 1
    return 1

    ex3: position = [5, 0], speed = [1, 2], target = 10
    i = 0: curTime = 5 > 0.0 true, res = 1, preTime = 5
    i = 1: curTime = 5 > 5 false, res = 1
    return 1
    */
}