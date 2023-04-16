/**https://leetcode.com/problems/steps-to-make-array-non-decreasing/ */
//You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
//Return the number of steps performed until nums becomes a non-decreasing array.


int totalSteps(int* nums, int numsSize){
    int i, j, k, count = 0, temp = 0;
    for(i = 0; i < numsSize; i++){
        for(j = i+1; j < numsSize; j++){
            if(nums[i] > nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                count++;
            }
        }
    }
    return count;

}

    