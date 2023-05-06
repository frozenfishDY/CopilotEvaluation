/**https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.


int findNumberOfLIS(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    int* count = (int*)malloc(sizeof(int) * numsSize);
    int max = 0;
    int maxCount = 0;
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
        count[i] = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }else if(dp[j] + 1 == dp[i]){
                    count[i] += count[j];
                }
            }
        }
        if(dp[i] > max){
            max = dp[i];
            maxCount = count[i];
        }else if(dp[i] == max){
            maxCount += count[i];
        }
    }
    return maxCount;


}

    