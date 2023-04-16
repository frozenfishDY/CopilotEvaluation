/**https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/ */
//There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:
//Eat one orange.
//If the number of remaining oranges n is divisible by 2 then you can eat n / 2 oranges.
//If the number of remaining oranges n is divisible by 3 then you can eat 2 * (n / 3) oranges.
//You can only choose one of the actions per day.
//Given the integer n, return the minimum number of days to eat n oranges.


class MinimumNumberOfDaysToEatNOranges {
    public int minDays(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = Math.min(dp[i], dp[i - 1] + 1);
            if(i % 2 == 0){
                dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            }
            if(i % 3 == 0){
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
            }
        }
        return dp[n];
        
    }
}
     
    