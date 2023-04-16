/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.


class FindAllGoodStrings {
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        int mod = 1000000007;
        int[][][] dp = new int[n + 1][s1.length() + 1][s2.length() + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= s1.length(); j++){
                for(int k = 0; k <= s2.length(); k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return dfs(n, s1, s2, evil, 0, 0, 0, dp) % mod;
        
        
    }
}
     
    