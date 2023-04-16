/**https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/ */
//You are given a 0-indexed integer array nums of length n. The number of ways to partition nums is the number of pivot indices that satisfy both conditions:
//1 <= pivot < n
//nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
//You are also given an integer k. You can choose to change the value of one element of nums to k, or to leave the array unchanged.
//Return the maximum possible number of ways to partition nums to satisfy both conditions after changing at most one element.


class MaximumNumberOfWaysToPartitionAnArray {
    public int waysToPartition(int[] nums, int k) {
        int n = nums.length;
        int[] pre = new int[n + 1];
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + (nums[i] < k ? -1 : 1);
        }
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i <= n; i++){
            res += map.getOrDefault(pre[i], 0);
            map.put(pre[i] + 1, map.getOrDefault(pre[i] + 1, 0) + 1);
        }
        return res;
        
    }
}
     
    