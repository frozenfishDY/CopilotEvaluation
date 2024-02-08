/**https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/ */
//You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
//You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
//You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
//Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.


class MinimumDifficultyOfAJobSchedule {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if (n < d) {
            return -1;
        }
        int[][] dp = new int[d][n];
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = Math.max(dp[0][i - 1], jobDifficulty[i]);
        }
        for (int i = 1; i < d; i++) {
            for (int j = i; j < n; j++) {
                int max = jobDifficulty[j];
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = j; k >= i; k--) {
                    max = Math.max(max, jobDifficulty[k]);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k - 1] + max);
                }
            }
        }
        return dp[d - 1][n - 1];
        
    }
}
     
    