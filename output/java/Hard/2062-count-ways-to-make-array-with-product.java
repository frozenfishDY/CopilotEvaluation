/**https://leetcode.com/problems/count-ways-to-make-array-with-product/ */
//You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 109 + 7.
//Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.


class CountWaysToMakeArrayWithProduct {
    public int[] waysToFillArray(int[][] queries) {
        int n = queries.length;
        int[] res = new int[n];
        int mod = (int)1e9 + 7;
        for(int i = 0; i < n; i++){
            int[] q = queries[i];
            int len = q[0];
            int prod = q[1];
            int[] dp = new int[prod + 1];
            dp[1] = 1;
            for(int j = 2; j <= prod; j++){
                for(int k = 1; k <= len; k++){
                    if(j % k == 0){
                        dp[j] = (dp[j] + dp[j / k]) % mod;
                    }
                }
            }
            res[i] = dp[prod];
        }
        return res;
        
    }
}
     
    