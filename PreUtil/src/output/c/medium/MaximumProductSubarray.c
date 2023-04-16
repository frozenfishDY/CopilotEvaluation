/**https://leetcode.com/problems/maximum-product-subarray/ */
//Given an integer array nums, find a subarray that has the largest product, and return the product.
//The test cases are generated so that the answer will fit in a 32-bit integer.


int maxProduct(int* nums, int numsSize){
    int max = nums[0];
    int min = nums[0];
    int result = nums[0];
    for(int i = 1; i < numsSize; i++){
        int temp = max;
        max = fmax(nums[i], fmax(nums[i] * max, nums[i] * min));
        min = fmin(nums[i], fmin(nums[i] * temp, nums[i] * min));
        if(max > result){
            result = max;
        }
    }
    return result;

}

    