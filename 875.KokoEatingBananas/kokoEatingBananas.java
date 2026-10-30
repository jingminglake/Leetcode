class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1; // min speed
        int right = 0; // max speed
        for (int p : piles) {
            if (p > right) right = p;
        }

        // 1: false, 2: false, ... true, maxSpeed: true
        // find the first true speed, right always point to last valid one
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean valid(int[] piles, int h, int speed) {
        int needH = 0;
        for (int p : piles) {
            int hh = p / speed;
            if (p % speed != 0) hh++;
            needH += hh;
            if (needH > h) return false;
        }
        return true;
    }
}

/*
piles = [3,6,7,11], h = 8
left = 1, right = 11
mid = 1 + (11 - 1) / 2 = 6
      valid: hh = 0 + 1 = 1,  needH = 1
             hh = 0 + 1 = 1,  needH = 2
             hh = 1 + 1 = 2,  needH = 4
             hh = 1 + 1 = 2,  needH = 6 < 8 valid: true -> right = 6

mid = 1 + (6 - 1)/2 = 3
      valid? hh = 1 + 0, needH = 1
             hh = 2 + 0, needH = 3
             hh = 2 + 1, needH = 6
             hh = 3 + 1, needH = 10 > 8 valid:false -> left = 3 + 1= 4

mid = 4 + (6 - 4)/2 = 5
     valid? hh = 0 + 1 = 1
            hh = 1 + 1 = 2
            hh = 1 + 1 = 2
            hh = 2 + 1 = 3, needH = 8 valid:true -> right = 5

mid = 4 + (5-4)/2= 4
     valid? true -> right = 4

4 < 4 false, return 4

ex2: [3,6,7,11], h = 100

left = 1, right = 11
mid = 6 valid: true -> right = 6
mid = 3 valid: true -> right = 3
mid = 2 valid: true -> right = 2
mid = 1 valid: true -> right = 1
1 < 1 false, return 1


*/