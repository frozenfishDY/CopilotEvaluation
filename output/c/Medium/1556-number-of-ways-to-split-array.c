/**https://leetcode.com/problems/number-of-ways-to-split-array/ */
//You are given a 0-indexed integer array nums of length n.
//nums contains a valid split at index i if the following are true:
//The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
//There is at least one element to the right of i. That is, 0 <= i < n - 1.
//Return the number of valid splits in nums.


int waysToSplitArray(int* nums, int numsSize){
    int i, j, k, count = 0, sum = 0, temp = 0;
    for(i = 0; i < numsSize; i++){
        sum = 0;
        for(j = i; j < numsSize; j++){
            if(nums[j] % p == 0){
                sum++;
            }
            if(sum <= k){
                count++;
            }
        }
    }
    return count;

}

    