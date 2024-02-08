/**https://leetcode.com/problems/k-divisible-elements-subarrays/ */
//Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
//Two arrays nums1 and nums2 are said to be distinct if:
//They are of different lengths, or
//There exists at least one index i where nums1[i] != nums2[i].
//A subarray is defined as a non-empty contiguous sequence of elements in an array.


int countDistinct(int* nums, int numsSize, int k, int p){
    int i, j, count = 0, sum = 0, temp = 0;
    for(i = 0; i < numsSize; i++){
        sum = 0;
        for(j = i; j < numsSize; j++){
            if(nums[j] % p == 0){
                sum++;
            }
            if(sum <= k){
                count++;
            }
        }
    }
    return count;

}

    