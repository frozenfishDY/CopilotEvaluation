/**https://leetcode.com/problems/jump-game-vi/ */
//You are given a 0-indexed integer array nums and an integer k.
//You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.
//You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.
//Return the maximum score you can get.


class JumpGameVi {
    public int maxResult(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        Deque<Integer> q = new LinkedList<>();
        q.offer(0);
        for(int i = 1; i < n; i++){
            while(!q.isEmpty() && q.peekFirst() < i - k){
                q.pollFirst();
            }
            dp[i] = dp[q.peekFirst()] + nums[i];
            while(!q.isEmpty() && dp[q.peekLast()] <= dp[i]){
                q.pollLast();
            }
            q.offer(i);
        }
        return dp[n - 1];
        
    }
}
     
    