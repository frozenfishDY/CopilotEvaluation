/**https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/ */
//Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
//Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lies on the dartboard.
//Given the integer r, return the maximum number of darts that can lie on the dartboard.


class MaximumNumberOfDartsInsideOfACircularDartboard {
    public int numPoints(int[][] darts, int r) {
        int n = darts.length;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int[] p1 = darts[i];
                int[] p2 = darts[j];
                int[] center = getCenter(p1, p2, r);
                if (center == null) {
                    continue;
                }
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (inCircle(darts[k], center, r)) {
                        cnt++;
                    }
                }
                ans = Math.max(ans, cnt);
            }
        }
        return ans;
        
    }
}
     
    