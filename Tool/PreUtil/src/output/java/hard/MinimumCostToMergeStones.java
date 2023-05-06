/**https://leetcode.com/problems/minimum-cost-to-merge-stones/ */
//There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
//A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
//Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.


class MinimumCostToMergeStones {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if((n-1)%(k-1)!=0) return -1;
        int[] prefix = new int[n+1];
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i]+stones[i];
        }
        int[][] dp = new int[n][n];
        for(int m=k;m<=n;m++){
            for(int i=0;i+m<=n;i++){
                int j = i+m-1;
                dp[i][j] = Integer.MAX_VALUE;
                for(int mid=i;mid<j;mid+=k-1){
                    dp[i][j] = Math.min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                }
                if((j-i)%(k-1)==0){
                    dp[i][j] += prefix[j+1]-prefix[i];
                }
            }
        }
        return dp[0][n-1];
        
    }
}
     
    