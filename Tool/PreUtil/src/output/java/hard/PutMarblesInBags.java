/**https://leetcode.com/problems/put-marbles-in-bags/ */
//You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
//Divide the marbles into the k bags according to the following rules:
//No bag is empty.
//If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
//If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
//The score after distributing the marbles is the sum of the costs of all the k bags.
//Return the difference between the maximum and minimum scores among marble distributions.


class PutMarblesInBags {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length;
        long[] sum = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + weights[i - 1];
        }
        long[][] dp = new long[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], Long.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = 0; l < i; l++) {
                    dp[i][j] = Math.min(dp[i][j], dp[l][j - 1] + sum[i] - sum[l]);
                }
            }
        }
        long max = 0;
        long min = Long.MAX_VALUE;
        for (int i = 1; i <= k; i++) {
            max = Math.max(max, dp[n][i]);
            min = Math.min(min, dp[n][i]);
        }
        return max - min;
        
    }
}
     
    