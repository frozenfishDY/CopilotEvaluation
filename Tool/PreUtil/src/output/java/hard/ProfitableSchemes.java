/**https://leetcode.com/problems/profitable-schemes/ */
//There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.
//Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.
//Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 10^9 + 7.


class ProfitableSchemes {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int mod = 1000000007;
        int[][] dp = new int[n + 1][minProfit + 1];
        dp[0][0] = 1;
        for (int k = 0; k < group.length; k++) {
            int g = group[k], p = profit[k];
            for (int i = n - g; i >= 0; i--) {
                for (int j = minProfit; j >= 0; j--) {
                    dp[i + g][Math.min(j + p, minProfit)] += dp[i][j];
                    dp[i + g][Math.min(j + p, minProfit)] %= mod;
                }
            }
        }
        int res = 0;
        for (int x : dp[n]) {
            res += x;
            res %= mod;
        }
        return res;
        
    }
}
     
    