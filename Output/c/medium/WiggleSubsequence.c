/**https://leetcode.com/problems/wiggle-subsequence/ */
//A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
//For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
//In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
//A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
//Given an integer array nums, return the length of the longest wiggle subsequence of nums.


int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2){
        return numsSize;
    }
    int* up = (int*)malloc(sizeof(int) * numsSize);
    int* down = (int*)malloc(sizeof(int) * numsSize);
    up[0] = 1;
    down[0] = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > nums[i - 1]){
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        }else if(nums[i] < nums[i - 1]){
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        }else{
            up[i] = up[i - 1];
            down[i] = down[i - 1];
        }
    }
    return fmax(up[numsSize - 1], down[numsSize - 1]);

}

    