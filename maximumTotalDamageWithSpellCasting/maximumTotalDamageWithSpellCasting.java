class Solution {
    public long maximumTotalDamage(int[] power) {
        if (power.length == 1) return power[0];
        Arrays.sort(power);
        long[] dpg = new long[power.length];
        long[] dph = new long[power.length];
        dph[0] = dpg[0] = power[0];
        if (power[1] == power[0] + 1 || power[1] == power[0] + 2) {
            dph[1] = power[1];
        } else {
            dph[1] = dph[0] + power[1];
        }
        dpg[1] = Math.max(dph[1], dpg[0]);
        for (int i = 2; i < dpg.length; i++) {
            if (power[i] == power[i - 1]) {
                dph[i] = dph[i - 1] + power[i];
                dpg[i] = Math.max(dph[i], dpg[i - 1]);
            } else {
                int j = i - 1;
                while (j >= 0 && power[i] - power[j] <= 2) j--;

                if (j >= 0)
                    dph[i] = dpg[j] + power[i];
                else dph[i] = power[i];

                dpg[i] = Math.max(dph[i], dpg[i - 1]);
            }
        }
        return dpg[dpg.length - 1];
    }
}