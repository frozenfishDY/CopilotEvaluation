/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


int sumSubarrayMins(int* arr, int arrSize){
    int result = 0;
    int dp[arrSize][arrSize];
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < arrSize; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < arrSize; i++){
        dp[i][i] = arr[i];
        result = result + arr[i];
    }
    for(int i = 1; i < arrSize; i++){
        for(int j = 0; j < arrSize - i; j++){
            dp[j][j + i] = dp[j][j + i - 1] < arr[j + i] ? dp[j][j + i - 1] : arr[j + i];
            result = result + dp[j][j + i];
        }
    }
    return result;

}

    