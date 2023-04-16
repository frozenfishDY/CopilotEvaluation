/**https://leetcode.com/problems/minimum-cost-for-tickets/ */
//You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
//Train tickets are sold in three different ways:
//a 1-day pass is sold for costs[0] dollars,
//a 7-day pass is sold for costs[1] dollars, and
//a 30-day pass is sold for costs[2] dollars.
//The passes allow that many days of consecutive travel.
//For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
//Return the minimum number of dollars you need to travel every day in the given list of days.


/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
var mincostTickets = function(days, costs) {
    let n = days.length;
    let dp = new Array(n + 1).fill(0);
    let dayset = new Set();
    for(let day of days){
        dayset.add(day);
    }
    for(let i = n - 1; i >= 0; i--){
        let day1 = days[i] + 1;
        let day7 = days[i] + 7;
        let day30 = days[i] + 30;
        let min1 = dp[i + 1] + costs[0];
        let min7 = dp[i + 1] + costs[1];
        let min30 = dp[i + 1] + costs[2];
        while(dayset.has(day1)){
            day1++;
        }
        while(dayset.has(day7)){
            day7++;
        }
        while(dayset.has(day30)){
            day30++;
        }
        let j1 = binarySearch(days, day1);
        let j7 = binarySearch(days, day7);
        let j30 = binarySearch(days, day30);
        min7 = Math.min(min7, dp[j7] + costs[1]);
        min30 = Math.min(min30, dp[j30] + costs[2]);
        dp[i] = Math.min(min1, min7, min30);
    }
    return dp[0];
    
    
};

    