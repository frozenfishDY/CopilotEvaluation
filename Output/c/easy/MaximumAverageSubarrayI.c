/**https://leetcode.com/problems/maximum-average-subarray-i/ */
//You are given an integer array nums consisting of n elements, and an integer k.
//Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.


double findMaxAverage(int* nums, int numsSize, int k){
    int i = 0;
    int j = 0;
    int temp = 0;
    int result = 0;
    int count = 0;
    for(i = 0; i < numsSize - 1; i++){
        for(j = 0; j < numsSize - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for(i = 0; i < numsSize - k + 1; i++){
        count = 0;
        for(j = i; j < i + k; j++){
            count += nums[j];
        }
        if(count > result){
            result = count;
        }
    }
    return (double)result / k;


}

    