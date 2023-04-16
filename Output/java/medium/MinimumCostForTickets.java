/**https://leetcode.com/problems/minimum-cost-for-tickets/ */
//You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
//Train tickets are sold in three different ways:
//a 1-day pass is sold for costs[0] dollars,
//a 7-day pass is sold for costs[1] dollars, and
//a 30-day pass is sold for costs[2] dollars.
//The passes allow that many days of consecutive travel.
//For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
//Return the minimum number of dollars you need to travel every day in the given list of days.


class MinimumCostForTickets {
    public int mincostTickets(int[] days, int[] costs) {
        int[] dp = new int[days.length];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = Math.min(costs[0], Math.min(costs[1], costs[2]));
        for(int i = 1; i < days.length; i++){
            int day = days[i];
            int cost = dp[i - 1] + costs[0];
            int j = i - 1;
            while(j >= 0 && days[j] + 6 >= day){
                j--;
            }
            if(j >= 0){
                cost = Math.min(cost, dp[j] + costs[1]);
            }else{
                cost = Math.min(cost, costs[1]);
            }
            j = i - 1;
            while(j >= 0 && days[j] + 29 >= day){
                j--;
            }
            if(j >= 0){
                cost = Math.min(cost, dp[j] + costs[2]);
            }else{
                cost = Math.min(cost, costs[2]);
            }
            dp[i] = cost;
        }
        return dp[days.length - 1];
        
    }
}

    