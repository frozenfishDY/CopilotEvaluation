/**https://leetcode.com/problems/house-robber-iv/ */
//There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
//The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
//You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
//You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
//Return the minimum capability of the robber out of all the possible ways to steal at least k houses.


class HouseRobberIv {
    public int minCapability(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        int[] sum = new int[n];
        sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i - 1] + nums[i];
        }
        for(int i = 0; i < k; i++){
            dp[i] = sum[i];
        }
        for(int i = k; i < n; i++){
            dp[i] = sum[i] - sum[i - k];
            for(int j = i - k + 1; j < i; j++){
                dp[i] = Math.min(dp[i], dp[j] + sum[i] - sum[j]);
            }
        }
        int res = Integer.MAX_VALUE;
        for(int i = n - k; i < n; i++){
            res = Math.min(res, dp[i]);
        }
        return res;
        
    }
}

    