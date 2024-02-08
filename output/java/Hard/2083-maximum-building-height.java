/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//The height of each building must be a non-negative integer.
//The height of the first building must be 0.
//The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.


class MaximumBuildingHeight {
    public int maxBuilding(int n, int[][] restrictions) {
        Arrays.sort(restrictions, (a, b) -> a[0] - b[0]);
        int m = restrictions.length;
        int[][] dp = new int[m][2];
        for(int i = 0; i < m; i++){
            dp[i][0] = restrictions[i][0];
            dp[i][1] = restrictions[i][1];
        }
        for(int i = 1; i < m; i++){
            dp[i][1] = Math.min(dp[i][1], dp[i - 1][1] + dp[i][0] - dp[i - 1][0]);
        }
        for(int i = m - 2; i >= 0; i--){
            dp[i][1] = Math.min(dp[i][1], dp[i + 1][1] + dp[i + 1][0] - dp[i][0]);
        }
        int res = 0;
        for(int i = 0; i < m - 1; i++){
            int left = dp[i][0];
            int right = dp[i + 1][0];
            int height = Math.min(dp[i][1], dp[i + 1][1]);
            res = Math.max(res, height + (right - left - 1) / 2);
        }
        if(m == 0 || dp[0][0] != 1){
            res = Math.max(res, dp[0][1] + dp[0][0] - 1);
        }
        if(m == 0 || dp[m - 1][0] != n){
            res = Math.max(res, dp[m - 1][1] + n - dp[m - 1][0]);
        }
        return res;
        
    }
}
     
    