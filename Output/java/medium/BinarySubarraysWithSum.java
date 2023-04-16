/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.


class BinarySubarraysWithSum {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        int[] preSum = new int[n + 1];
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i <= n; i++){
            res += map.getOrDefault(preSum[i] - goal, 0);
            map.put(preSum[i], map.getOrDefault(preSum[i], 0) + 1);
        }
        return res;
        
    }
}

    