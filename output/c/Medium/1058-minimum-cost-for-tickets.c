/**https://leetcode.com/problems/minimum-cost-for-tickets/ */
//You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
//Train tickets are sold in three different ways:
//a 1-day pass is sold for costs[0] dollars,
//a 7-day pass is sold for costs[1] dollars, and
//a 30-day pass is sold for costs[2] dollars.
//The passes allow that many days of consecutive travel.
//For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
//Return the minimum number of dollars you need to travel every day in the given list of days.


int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int dp[daysSize];
    for(int i = 0; i < daysSize; i++){
        dp[i] = 0;
    }
    for(int i = 0; i < daysSize; i++){
        int min = 0;
        for(int j = 0; j < i; j++){
            if(days[i] - days[j] < 7){
                min = min > dp[j] ? min : dp[j];
            }
        }
        dp[i] = min + costs[1];
        min = 0;
        for(int j = 0; j < i; j++){
            if(days[i] - days[j] < 30){
                min = min > dp[j] ? min : dp[j];
            }
        }
        dp[i] = dp[i] < min + costs[2] ? dp[i] : min + costs[2];
        dp[i] = dp[i] < dp[i - 1] + costs[0] ? dp[i] : dp[i - 1] + costs[0];
    }
    return dp[daysSize - 1];

}

    