/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.


bool splitArraySameAverage(int* nums, int numsSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int sum = 0;
    for(i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    int** dp = (int**)malloc(sizeof(int*) * (numsSize + 1));
    for(i = 0; i <= numsSize; i++){
        dp[i] = (int*)malloc(sizeof(int) * (sum + 1));
        for(j = 0; j <= sum; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(i = 0; i < numsSize; i++){
        for(j = sum; j >= nums[i]; j--){
            for(k = numsSize; k >= 1; k--){
                dp[k][j] = dp[k][j] || dp[k - 1][j - nums[i]];
            }
        }
    }
    for(i = 1; i < numsSize; i++){
        if(sum * i % numsSize == 0 && dp[i][sum * i / numsSize]){
            return true;
        }
    }
    return false;

}

    