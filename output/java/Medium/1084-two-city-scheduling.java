/**https://leetcode.com/problems/two-city-scheduling/ */
//A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.


class TwoCityScheduling {
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length;
        int[][] dp = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(j == 0){
                    dp[i][j] = dp[i - 1][j] + costs[i - 1][0];
                }else{
                    dp[i][j] = Math.min(dp[i - 1][j] + costs[i - 1][0], dp[i - 1][j - 1] + costs[i - 1][1]);
                }
            }
        }
        return dp[n][n / 2];
        
    }
}

    