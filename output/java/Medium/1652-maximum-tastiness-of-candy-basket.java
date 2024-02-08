/**https://leetcode.com/problems/maximum-tastiness-of-candy-basket/ */
//You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.
//The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.
//Return the maximum tastiness of a candy basket.


class MaximumTastinessOfCandyBasket {
    public int maximumTastiness(int[] price, int k) {
        int n = price.length;
        int[][] dp = new int[n + 1][k + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i - 1][j];
                if(j <= i){
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + price[i - 1]);
                }
            }
        }
        return dp[n][k];
        
    }
}

    