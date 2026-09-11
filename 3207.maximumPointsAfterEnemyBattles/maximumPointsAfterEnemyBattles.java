class Solution {
    public long maximumPoints(int[] enemyEnergies, int currentEnergy) {
        int minEnemyEnergy = enemyEnergies[0];
        long totalEnergies = 0;
        for (int i = 0; i < enemyEnergies.length; i++) {
            totalEnergies += enemyEnergies[i];
            minEnemyEnergy = Math.min(minEnemyEnergy, enemyEnergies[i]);
        }
        if (currentEnergy >= minEnemyEnergy)
            return (totalEnergies - minEnemyEnergy + currentEnergy) / minEnemyEnergy;
        else return 0;
    }
}