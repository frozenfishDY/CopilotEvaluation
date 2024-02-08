/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.


class ShortestSubarrayWithSumAtLeastK {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int res = Integer.MAX_VALUE;
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i <= n; i++) {
            while (!deque.isEmpty() && sum[i] <= sum[deque.peekLast()]) {
                deque.pollLast();
            }
            while (!deque.isEmpty() && sum[i] - sum[deque.peekFirst()] >= k) {
                res = Math.min(res, i - deque.pollFirst());
            }
            deque.offerLast(i);
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
    }
}
     
    