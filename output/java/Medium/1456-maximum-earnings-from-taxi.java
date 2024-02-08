/**https://leetcode.com/problems/maximum-earnings-from-taxi/ */
//There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction you are going, and you want to drive from point 1 to point n to make money by picking up passengers. You cannot change the direction of the taxi.
//The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.
//For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.
//Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.
//Note: You may drop off a passenger and pick up a different passenger at the same point.


class MaximumEarningsFromTaxi {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Arrays.sort(rides, (a, b) -> a[0] - b[0]);
        long[] dp = new long[rides.length + 1];
        for(int i = 1; i < dp.length; i++){
            dp[i] = Math.max(dp[i - 1], dp[i]);
            int index = binarySearch(rides, rides[i - 1][1]);
            dp[index] = Math.max(dp[index], dp[i - 1] + rides[i - 1][1] - rides[i - 1][0] + rides[i - 1][2]);
        }
        return dp[dp.length - 1];
        
        
    }
}
     
    