/**https://leetcode.com/problems/tallest-billboard/ */
//You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.
//You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.
//Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.


class TallestBillboard {
    public int tallestBillboard(int[] rods) {
        int n = rods.length;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += rods[i];
        }
        int[][] dp = new int[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                if(dp[i][j]>=0){
                    dp[i+1][j] = Math.max(dp[i+1][j],dp[i][j]);
                    dp[i+1][j+rods[i]] = Math.max(dp[i+1][j+rods[i]],dp[i][j]);
                    dp[i+1][Math.abs(j-rods[i])] = Math.max(dp[i+1][Math.abs(j-rods[i])],dp[i][j]+Math.min(j,rods[i]));
                }
            }
        }
        return dp[n][0];
        
    }
}
     
    