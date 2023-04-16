/**https://leetcode.com/problems/maximum-sum-circular-subarray/ */
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


class MaximumSumCircularSubarray {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int[] preSum = new int[n + 1];
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int res = Integer.MIN_VALUE;
        int min = 0;
        for(int i = 1; i <= n; i++){
            res = Math.max(res, preSum[i] - min);
            min = Math.min(min, preSum[i]);
        }
        int max = 0;
        for(int i = n; i >= 1; i--){
            max = Math.max(max, preSum[i]);
            res = Math.max(res, max - preSum[i - 1]);
        }
        return res;
        
        
    }
}

    