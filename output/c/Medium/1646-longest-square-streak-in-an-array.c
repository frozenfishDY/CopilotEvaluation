/**https://leetcode.com/problems/longest-square-streak-in-an-array/ */
//You are given an integer array nums. A subsequence of nums is called a square streak if:
//The length of the subsequence is at least 2, and
//after sorting the subsequence, each element (except the first element) is the square of the previous number.
//Return the length of the longest square streak in nums, or return -1 if there is no square streak.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


int longestSquareStreak(int* nums, int numsSize){
    int result = 0;
    int dp[numsSize];
    for(int i = 0; i < numsSize; i++){
        dp[i] = 0;
    }
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] == nums[j] * nums[j]){
                dp[i] = dp[j] + 1;
                result = result > dp[i] ? result : dp[i];
            }
        }
    }
    return result == 0 ? -1 : result + 1;

}

    