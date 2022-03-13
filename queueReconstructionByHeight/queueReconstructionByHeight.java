class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (a, b) -> a[0] != b[0] ? a[0] - b[0] : b[1] - a[1]);
        for (int i = people.length - 2; i >= 0; i--) {
            int h = people[i][0];
            int k = people[i][1];
            int j = i;
            while (j != i + k) {
                people[j][0] = people[j + 1][0];
                people[j][1] = people[j + 1][1];
                j++;
            }
            people[i + k][0] = h;
            people[i + k][1] = k;
        }
        return people;
    }
}
