/**https://leetcode.com/problems/longest-continuous-increasing-subsequence/ */
//Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.
//A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].


int findLengthOfLCIS(int* nums, int numsSize){
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
    for(i = 0; i < numsSize - 1; i++){
        if(nums[i] < nums[i + 1]){
            count++;
        }else{
            count = 0;
        }
        if(count > result){
            result = count;
        }
    }
    return result + 1;

}

    