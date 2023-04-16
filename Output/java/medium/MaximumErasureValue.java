/**https://leetcode.com/problems/maximum-erasure-value/ */
//You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
//Return the maximum score you can get by erasing exactly one subarray.
//An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


class MaximumErasureValue {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n + 1];
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int[] dp = new int[n + 1];
        int res = 0;
        int[] last = new int[10001];
        Arrays.fill(last, -1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if(last[nums[i - 1]] != -1){
                dp[i] = Math.max(dp[i], dp[last[nums[i - 1]]] + pre[i] - pre[last[nums[i - 1]] + 1]);
            }
            last[nums[i - 1]] = i - 1;
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    