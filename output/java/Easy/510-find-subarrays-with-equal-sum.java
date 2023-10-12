/**https://leetcode.com/problems/find-subarrays-with-equal-sum/ */
//Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
//Return true if these subarrays exist, and false otherwise.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [4,2,4]
//Output: true
//Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
//Example 2:
//Input: nums = [1,2,3,4,5]
//Output: false
//Explanation: No two subarrays of size 2 have the same sum.
//Example 3:
//Input: nums = [0,0,0]
//Output: true
//Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
//Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
// 
//Constraints:
//	2 <= nums.length <= 1000
//	-109 <= nums[i] <= 109
class Solution {
    public boolean findSubarrays(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            map.putIfAbsent(prefix[i], new ArrayList<>());
            map.get(prefix[i]).add(i);
        }
        for (int val : map.keySet()) {
            List<Integer> list = map.get(val);
            if (list.size() < 2) continue;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i + 1) - list.get(i) > 1) return true;
            }
        }
        return false;
    }
}