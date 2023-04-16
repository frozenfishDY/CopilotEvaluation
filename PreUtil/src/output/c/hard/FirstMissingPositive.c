/**https://leetcode.com/problems/first-missing-positive/ */
//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) time and uses constant extra space.


int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] <= 0){
            nums[i] = numsSize + 1;
        }
    }
    for(i = 0; i < numsSize; i++){
        if(nums[i] > 0 && nums[i] <= numsSize){
            temp = nums[i];
            nums[i] = 0;
            while(temp > 0 && temp <= numsSize && nums[temp - 1] != temp){
                j = temp;
                temp = nums[temp - 1];
                nums[j - 1] = j;
            }
        }
    }
    for(i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            return i + 1;
        }
    }
    return numsSize + 1;

}

    