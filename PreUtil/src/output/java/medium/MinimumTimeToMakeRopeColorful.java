/**https://leetcode.com/problems/minimum-time-to-make-rope-colorful/ */
//Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
//Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
//Return the minimum time Bob needs to make the rope colorful.


class MinimumTimeToMakeRopeColorful {
    public int minCost(String colors, int[] neededTime) {
        int n = colors.length();
        int[][] dp = new int[n][3];
        for(int i = 0; i < n; i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        for(int i = 0; i < 3; i++){
            if(colors.charAt(0) == '?' || colors.charAt(0) == (char)('a' + i)){
                dp[0][i] = neededTime[0];
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                if(colors.charAt(i) == '?' || colors.charAt(i) == (char)('a' + j)){
                    for(int k = 0; k < 3; k++){
                        if(j != k){
                            dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + neededTime[i]);
                        }
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 3; i++){
            ans = Math.min(ans, dp[n - 1][i]);
        }
        return ans;
        
    }
}
     
    