/**https://leetcode.com/problems/minimum-cost-to-set-cooking-time/ */
//A generic microwave supports cooking times for:
//at least 1 second.
//at most 99 minutes and 99 seconds.
//To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,
//You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
//You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
//You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
//You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
//You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.
//There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.
//Return the minimum cost to set targetSeconds seconds of cooking time.
//Remember that one minute consists of 60 seconds.


class MinimumCostToSetCookingTime {
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int[] digits = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int[][] dp = new int[10][6000];
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 6000; j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[startAt][0] = 0;
        for(int i = 0; i < 6000; i++){
            for(int j = 0; j < 10; j++){
                if(dp[j][i] == Integer.MAX_VALUE){
                    continue;
                }
                for(int k = 0; k < 10; k++){
                    int next = i + (j * 60 + k);
                    if(next >= 6000){
                        continue;
                    }
                    int cost = dp[j][i] + Math.abs(k - j) * moveCost + k * pushCost;
                    dp[k][next] = Math.min(dp[k][next], cost);
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < 10; i++){
            res = Math.min(res, dp[i][targetSeconds]);
        }
        return res;
        
    }
}
     
    