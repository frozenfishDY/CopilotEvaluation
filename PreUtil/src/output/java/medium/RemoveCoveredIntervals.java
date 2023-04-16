/**https://leetcode.com/problems/remove-covered-intervals/ */
//Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
//The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
//Return the number of remaining intervals.


class RemoveCoveredIntervals {
    public int removeCoveredIntervals(int[][] intervals) {
        int n = intervals.length;
        int[][] dp = new int[n + 1][2];
        int max = 0;
        for(int i = 1; i <= n; i++){
            dp[i][0] = intervals[i - 1][0];
            dp[i][1] = intervals[i - 1][1];
            if(i >= 2){
                if(dp[i][0] >= dp[i - 1][0] && dp[i][1] <= dp[i - 1][1]){
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1];
                }
            }
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(dp[i][0] == dp[i - 1][0] && dp[i][1] == dp[i - 1][1]){
                count++;
            }
        }
        return n - count;
        
    }
}

    