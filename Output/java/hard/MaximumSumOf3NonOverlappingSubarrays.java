/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.


class MaximumSumOf3NonOverlappingSubarrays {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] sums = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (int i = k, total = sums[k] - sums[0]; i < n; i++) {
            if (sums[i + 1] - sums[i + 1 - k] > total) {
                left[i] = i + 1 - k;
                total = sums[i + 1] - sums[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }
        right[n - k] = n - k;
        for (int i = n - k - 1, total = sums[n] - sums[n - k]; i >= 0; i--) {
            if (sums[i + k] - sums[i] >= total) {
                right[i] = i;
                total = sums[i + k] - sums[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        int[] ans = new int[]{-1, -1, -1};
        for (int i = k; i <= n - 2 * k; i++) {
            int l = left[i - 1], r = right[i + k];
            int total = (sums[i + k] - sums[i]) + (sums[l + k] - sums[l]) + (sums[r + k] - sums[r]);
            if (ans[0] == -1 || total > (sums[ans[0] + k] - sums[ans[0]]) + (sums[ans[1] + k] - sums[ans[1]]) + (sums[ans[2] + k] - sums[ans[2]])) {
                ans[0] = l;
                ans[1] = i;
                ans[2] = r;
            }
        }
        return ans;
        
    }
}
     
    