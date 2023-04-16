/**https://leetcode.com/problems/find-the-most-competitive-subsequence/ */
//Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
//An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
//We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostCompetitive(int* nums, int numsSize, int k, int* returnSize){
    int* arr = malloc(k * sizeof(int));
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        while(count > 0 && arr[count - 1] > nums[i] && count + numsSize - i > k){
            count--;
        }
        if(count < k){
            arr[count++] = nums[i];
        }
    }
    *returnSize = count;
    return arr;

}

    