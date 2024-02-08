/**https://leetcode.com/problems/subarray-product-less-than-k/ */
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.


int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if(k <= 1){
        return 0;
    }
    int count = 0;
    int product = 1;
    int left = 0;
    int right = 0;
    while(right < numsSize){
        product *= nums[right];
        while(product >= k){
            product /= nums[left++];
        }
        count += right - left + 1;
        right++;
    }
    return count;

}

    