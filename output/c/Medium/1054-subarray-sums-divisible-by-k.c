/**https://leetcode.com/problems/subarray-sums-divisible-by-k/ */
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.


int subarraysDivByK(int* nums, int numsSize, int k){
    int* count = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++){
        count[i] = 0;
    }
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        count[((sum % k) + k) % k]++;
    }
    int result = 0;
    for(int i = 0; i < k; i++){
        result += count[i] * (count[i] - 1) / 2;
    }
    return result + count[0];

}

    