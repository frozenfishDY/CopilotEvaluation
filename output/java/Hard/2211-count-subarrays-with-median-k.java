/**https://leetcode.com/problems/count-subarrays-with-median-k/ */
//You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
//Return the number of non-empty subarrays in nums that have a median equal to k.
//Note:
//The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
//For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
//A subarray is a contiguous part of an array.


class CountSubarraysWithMedianK {
    public int countSubarrays(int[] nums, int k) {
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
     
    