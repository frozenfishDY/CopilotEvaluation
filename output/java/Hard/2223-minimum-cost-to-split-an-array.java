/**https://leetcode.com/problems/minimum-cost-to-split-an-array/ */
//You are given an integer array nums and an integer k.
//Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.
//Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.
//For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
//The importance value of a subarray is k + trimmed(subarray).length.
//For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.
//Return the minimum possible cost of a split of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.


class MinimumCostToSplitAnArray {
    public int minCost(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int[] count = new int[n + 1];
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            count[nums[i - 1]]++;
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j <= k; j++) {
                int l = 0;
                int r = i;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (count[nums[mid - 1]] == 1) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                dp[i] = Math.min(dp[i], dp[l] + i - l - (sum[i] - sum[l]));
            }
        }
        return dp[n];
        
    }
}
     
    