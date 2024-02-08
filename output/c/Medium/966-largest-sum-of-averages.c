/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.


double largestSumOfAverages(int* nums, int numsSize, int k){
    double* dp = (double*)malloc(sizeof(double) * numsSize);
    double sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        dp[i] = sum / (i + 1);
    }
    for(int i = 1; i < k; i++){
        for(int j = numsSize - 1; j >= i; j--){
            sum = 0;
            for(int l = j; l >= i; l--){
                sum += nums[l];
                dp[j] = fmax(dp[j], dp[l - 1] + sum / (j - l + 1));
            }
        }
    }
    return dp[numsSize - 1];

}

    