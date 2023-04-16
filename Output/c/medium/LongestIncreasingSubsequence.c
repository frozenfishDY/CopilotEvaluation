/**https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.


int lengthOfLIS(int* nums, int numsSize){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        result[i] = 1;
    }
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                result[i] = fmax(result[i], result[j] + 1);
            }
        }
    }
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        if(result[i] > max){
            max = result[i];
        }
    }
    return max;

}

    