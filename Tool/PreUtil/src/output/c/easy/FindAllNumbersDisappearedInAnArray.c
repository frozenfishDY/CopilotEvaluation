/**https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/ */
//Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * numsSize);
    int i = 0;
    int j = 0;
    while(i < numsSize){
        result[i] = i + 1;
        i++;
    }
    i = 0;
    while(i < numsSize){
        result[nums[i] - 1] = 0;
        i++;
    }
    i = 0;
    while(i < numsSize){
        if(result[i] != 0){
            result[j] = result[i];
            j++;
        }
        i++;
    }
    *returnSize = j;
    return result;

}

    