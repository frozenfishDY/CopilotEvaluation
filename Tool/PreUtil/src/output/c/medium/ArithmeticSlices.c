/**https://leetcode.com/problems/arithmetic-slices/ */
//An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//A subarray is a contiguous subsequence of the array.


int numberOfArithmeticSlices(int* nums, int numsSize){
    if(numsSize < 3){
        return 0;
    }
    int* result = (int*)malloc(sizeof(int) * numsSize);
    result[0] = 0;
    result[1] = 0;
    for(int i = 2; i < numsSize; i++){
        if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
            result[i] = result[i - 1] + 1;
        }else{
            result[i] = 0;
        }
    }
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        count += result[i];
    }
    return count;

}

    