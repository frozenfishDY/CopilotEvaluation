/**https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.


int subarrayLCM(int* nums, int numsSize, int k){
    int count = 0;
    int start = 0;
    int end = 0;
    int lcm = 1;
    while(end < numsSize){
        lcm = lcm * nums[end] / gcd(lcm, nums[end]);
        while(lcm > k){
            lcm = lcm / nums[start];
            start++;
        }
        if(lcm == k){
            count++;
        }
        end++;
    }
    return count;

}

    