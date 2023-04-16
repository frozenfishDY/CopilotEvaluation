/**https://leetcode.com/problems/rotate-array/ */
//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


void rotate(int* nums, int numsSize, int k){
    int temp[numsSize];
    for(int i = 0; i < numsSize; i++){
        temp[(i + k) % numsSize] = nums[i];
    }
    for(int i = 0; i < numsSize; i++){
        nums[i] = temp[i];
    }

}

    