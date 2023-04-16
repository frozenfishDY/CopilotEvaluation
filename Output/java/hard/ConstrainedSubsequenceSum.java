/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.


class ConstrainedSubsequenceSum {
    public int constrainedSubsetSum(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        int max = Integer.MIN_VALUE;
        Deque<Integer> dq = new LinkedList<>();
        for(int i = 0; i < n; i++){
            dp[i] = nums[i];
            if(!dq.isEmpty()){
                dp[i] = Math.max(dp[i], nums[i] + dq.peekFirst());
            }
            max = Math.max(max, dp[i]);
            while(!dq.isEmpty() && dq.peekLast() < dp[i]){
                dq.pollLast();
            }
            dq.offerLast(dp[i]);
            if(i >= k && dq.peekFirst() == dp[i - k]){
                dq.pollFirst();
            }
        }
        return max;
        
    }
}
     
    