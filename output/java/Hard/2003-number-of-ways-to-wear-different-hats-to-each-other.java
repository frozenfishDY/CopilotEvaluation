/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 10^9 + 7.


class NumberOfWaysToWearDifferentHatsToEachOther {
    public int numberWays(List<List<Integer>> hats) {
        int n = hats.size();
        int mod = 1000000007;
        int[][] dp = new int[41][1 << n];
        dp[0][0] = 1;
        for(int i = 1; i <= 40; i++){
            for(int j = 0; j < (1 << n); j++){
                dp[i][j] = dp[i - 1][j];
                for(int k = 0; k < n; k++){
                    if((j & (1 << k)) == 0 && hats.get(k).contains(i)){
                        dp[i][j] = (dp[i][j] + dp[i - 1][j | (1 << k)]) % mod;
                    }
                }
            }
        }
        return dp[40][(1 << n) - 1];
        
    }
}
     
    