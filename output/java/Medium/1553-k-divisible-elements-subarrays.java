/**https://leetcode.com/problems/k-divisible-elements-subarrays/ */
//Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
//Two arrays nums1 and nums2 are said to be distinct if:
//They are of different lengths, or
//There exists at least one index i where nums1[i] != nums2[i].
//A subarray is defined as a non-empty contiguous sequence of elements in an array.


class KDivisibleElementsSubarrays {
    public int countDistinct(int[] nums, int k, int p) {
        int[] count = new int[p];
        int sum = 0;
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int mod = sum % p;
            if (mod < 0) {
                mod += p;
            }
            if (mod == 0) {
                result++;
            }
            if (i >= k) {
                sum -= nums[i - k];
            }
            if (i >= k - 1) {
                result += count[mod];
                count[mod]++;
            }
        }
        return result;
        
    }
}
     
    