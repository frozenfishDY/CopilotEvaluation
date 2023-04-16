/**https://leetcode.com/problems/longest-harmonious-subsequence/ */
//We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
//Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
//A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


int findLHS(int* nums, int numsSize){
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
    for(i = 0; i < numsSize; i++){
        count = 1;
        for(j = i + 1; j < numsSize; j++){
            if(nums[j] - nums[i] == 1){
                count++;
            }
            else if(nums[j] - nums[i] > 1){
                break;
            }
        }
        if(count > result){
            result = count;
        }
    }
    return result;

}

    