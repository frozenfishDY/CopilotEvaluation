/**https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/ */
//You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
//There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
//Return the minimum possible maximum working time of any assignment.


class FindMinimumTimeToFinishAllJobs {
    public int minimumTimeRequired(int[] jobs, int k) {
        int n = jobs.length;
        int[] dp = new int[1 << n];
        Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        for(int mask = 1; mask < (1 << n); mask++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(((mask >> i) & 1) > 0){
                    sum += jobs[i];
                }
            }
            for(int i = 0; i < n; i++){
                if(((mask >> i) & 1) > 0){
                    dp[mask] = Math.min(dp[mask], Math.max(dp[mask ^ (1 << i)], sum));
                }
            }
        }
        return dp[(1 << n) - 1];
        
    }
}
     
    