/**https://leetcode.com/problems/fair-distribution-of-cookies/ */
//You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
//The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
//Return the minimum unfairness of all distributions.


class FairDistributionOfCookies {
    public int distributeCookies(int[] cookies, int k) {
        Arrays.sort(cookies);
        int n = cookies.length;
        int[][] dp = new int[n][k];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int i = 0; i < n; i++){
            dp[i][0] = cookies[i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < k; j++){
                for(int l = 0; l < i; l++){
                    dp[i][j] = Math.min(dp[i][j], dp[l][j-1] + cookies[i] - cookies[l]);
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            min = Math.min(min, dp[i][k-1]);
        }
        return min;
        
    }
}
     
    