/**https://leetcode.com/problems/longest-arithmetic-subsequence/ */
//Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//Note that:
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).


int longestArithSeqLength(int* nums, int numsSize){
    int** dp = (int**)malloc(sizeof(int*) * numsSize);
    for(int i = 0; i < numsSize; i++){
        dp[i] = (int*)malloc(sizeof(int) * 20001);
        for(int j = 0; j < 20001; j++){
            dp[i][j] = 1;
        }
    }
    int max = 0;
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i] - nums[j] + 10000;
            dp[i][diff] = dp[j][diff] + 1;
            if(dp[i][diff] > max){
                max = dp[i][diff];
            }
        }
    }
    return max;

}

    