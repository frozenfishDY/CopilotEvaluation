/**https://leetcode.com/problems/summary-ranges/ */
//You are given a sorted unique integer array nums.
//A range [a,b] is the set of all integers from a to b (inclusive).
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//Each range [a,b] in the list should be output as:
//"a->b" if a != b
//"a" if a == b


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    char **result = (char **)malloc(sizeof(char *) * numsSize);
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    while(i < numsSize){
        j = i;
        while(j < numsSize - 1 && nums[j] + 1 == nums[j + 1]){
            j++;
        }
        if(i == j){
            result[k] = (char *)malloc(sizeof(char) * 10);
            sprintf(result[k], "%d", nums[i]);
            k++;
        }else{
            result[k] = (char *)malloc(sizeof(char) * 20);
            sprintf(result[k], "%d->%d", nums[i], nums[j]);
            k++;
        }
        i = j + 1;
    }
    *returnSize = k;
    return result;

}

    