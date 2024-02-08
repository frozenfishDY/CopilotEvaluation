/**https://leetcode.com/problems/minimum-absolute-sum-difference/ */
//You are given two positive integer arrays nums1 and nums2, both of length n.
//The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
//You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.
//Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.
//|x| is defined as:
//x if x >= 0, or
//-x if x < 0.


public class Solution {
    public int MinAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int mod = 1000000007;
        int sum = 0;
        int max = 0;
        int index = 0;
        int[] arr = new int[nums1.Length];
        for(int i = 0; i < nums1.Length; i++){
            arr[i] = Math.Abs(nums1[i] - nums2[i]);
            sum += arr[i];
        }
        for(int i = 0; i < nums1.Length; i++){
            for(int j = 0; j < nums1.Length; j++){
                if(Math.Abs(nums1[j] - nums2[i]) < arr[i]){
                    if(arr[i] - Math.Abs(nums1[j] - nums2[i]) > max){
                        max = arr[i] - Math.Abs(nums1[j] - nums2[i]);
                        index = i;
                    }
                }
            }
        }
        sum = sum - arr[index] + max;
        return sum % mod;
        
    }
}

    