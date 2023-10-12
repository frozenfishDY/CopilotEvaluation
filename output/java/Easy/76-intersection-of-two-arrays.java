/**https://leetcode.com/problems/intersection-of-two-arrays/ */
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
// 
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 1000
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> s = new HashSet<>();
        Set<Integer> ans = new HashSet<>();
        for (int i : nums1) s.add(i);
        for (int i : nums2) {
            if (s.contains(i)) ans.add(i);
        }
        int[] res = new int[ans.size()];
        int i = 0;
        for (int x : ans) res[i++] = x;
        return res;
    }
}