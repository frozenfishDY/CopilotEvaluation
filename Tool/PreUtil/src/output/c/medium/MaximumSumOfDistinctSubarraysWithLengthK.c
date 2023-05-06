/**https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/ */
//You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//The length of the subarray is k, and
//All the elements of the subarray are distinct.
//Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


long long maximumSubarraySum(int* nums, int numsSize, int k){
    long long sum = 0;
    for(int i = 0; i < k; i++){
        sum += nums[i];
    }
    long long maxSum = sum;
    for(int i = k; i < numsSize; i++){
        sum += nums[i] - nums[i - k];
        maxSum = fmax(maxSum, sum);
    }
    return maxSum;

}

    