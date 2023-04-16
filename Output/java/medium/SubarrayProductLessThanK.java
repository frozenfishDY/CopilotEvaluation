/**https://leetcode.com/problems/subarray-product-less-than-k/ */
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.


class SubarrayProductLessThanK {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int left = 0;
        int right = 0;
        int res = 0;
        int prod = 1;
        while(right < nums.length){
            prod *= nums[right];
            while(prod >= k && left <= right){
                prod /= nums[left];
                left++;
            }
            res += right - left + 1;
            right++;
        }
        return res;
        
    }
}

    