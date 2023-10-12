/**https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/ */
//Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.
// 
//Example 1:
//Input: nums1 = [4,1,3], nums2 = [5,7]
//Output: 15
//Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
//Example 2:
//Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
//Output: 3
//Explanation: The number 3 contains the digit 3 which exists in both arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 9
//	1 <= nums1[i], nums2[i] <= 9
//	All digits in each array are unique.
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        boolean[] cnt = new boolean[10];
        for (int num : nums1) {
            cnt[num] = true;
        }
        for (int num : nums2) {
            cnt[num] = true;
        }
        int res = 0;
        for (int i = 1; i < 10; i++) {
            if (cnt[i]) {
                res = i;
                break;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (cnt[i]) {
                res = res * 10 + i;
            }
        }
        return res;
    }
}