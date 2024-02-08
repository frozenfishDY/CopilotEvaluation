/**https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/ */
//There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).
//There are n + 1 taps located at points [0, 1, ..., n] in the garden.
//Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.
//Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.


class MinimumNumberOfTapsToOpenToWaterAGarden {
    public int minTaps(int n, int[] ranges) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int left = Math.max(0, i - ranges[i]);
            int right = Math.min(n, i + ranges[i]);
            for (int j = left; j <= right; j++) {
                dp[j] = Math.min(dp[j], dp[left] + 1);
            }
        }
        return dp[n] == Integer.MAX_VALUE ? -1 : dp[n];
        
    }
}
     
    