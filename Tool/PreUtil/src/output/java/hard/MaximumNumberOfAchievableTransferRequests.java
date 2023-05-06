/**https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/ */
//We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.
//You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.
//All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.
//Return the maximum number of achievable requests.


class MaximumNumberOfAchievableTransferRequests {
    public int maximumRequests(int n, int[][] requests) {
        int m = requests.length;
        int[] dp = new int[1 << m];
        for(int i = 0; i < (1 << m); i++){
            int[] count = new int[n];
            for(int j = 0; j < m; j++){
                if(((i >> j) & 1) == 1){
                    count[requests[j][0]]--;
                    count[requests[j][1]]++;
                }
            }
            boolean flag = true;
            for(int j = 0; j < n; j++){
                if(count[j] != 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                dp[i] = Integer.bitCount(i);
            }
        }
        for(int i = 0; i < (1 << m); i++){
            for(int j = i; j > 0; j = (j - 1) & i){
                dp[i] = Math.max(dp[i], dp[j] + dp[i ^ j]);
            }
        }
        return dp[(1 << m) - 1];
        
    }
}
     
    