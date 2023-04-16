/**https://leetcode.com/problems/set-mismatch/ */
//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 2);
    int *count = (int *)malloc(sizeof(int) * (numsSize + 1));
    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    for(int i = 1; i <= numsSize; i++){
        if(count[i] == 2){
            result[0] = i;
        }else if(count[i] == 0){
            result[1] = i;
        }
    }
    *returnSize = 2;
    return result;

}

    