/**https://leetcode.com/problems/partition-array-for-maximum-sum/ */
//Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.


int maxSumAfterPartitioning(int* arr, int arrSize, int k){
    int* dp = (int*)malloc(sizeof(int) * arrSize);
    memset(dp, 0, sizeof(int) * arrSize);
    for(int i = 0; i < arrSize; i++){
        int max = 0;
        for(int j = 1; j <= k && i - j + 1 >= 0; j++){
            max = fmax(max, arr[i - j + 1]);
            dp[i] = fmax(dp[i], (i - j >= 0 ? dp[i - j] : 0) + max * j);
        }
    }
    return dp[arrSize - 1];

}

    