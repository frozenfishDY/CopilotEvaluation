/**https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.


int maxCoins(int* nums, int numsSize){
    int* newNums = (int*)malloc(sizeof(int) * (numsSize + 2));
    int n = 1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0) newNums[n++] = nums[i];
    }
    newNums[0] = newNums[n++] = 1;
    int** dp = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        dp[i] = (int*)malloc(sizeof(int) * n);
        memset(dp[i], 0, sizeof(int) * n);
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 2; j < n; j++){
            for(int k = i + 1; k < j; k++){
                dp[i][j] = fmax(dp[i][j], dp[i][k] + dp[k][j] + newNums[i] * newNums[k] * newNums[j]);
            }
        }
    }
    return dp[0][n - 1];

}

    