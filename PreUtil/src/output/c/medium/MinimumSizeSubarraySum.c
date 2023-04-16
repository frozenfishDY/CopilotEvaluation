/**https://leetcode.com/problems/minimum-size-subarray-sum/ */
//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


int minSubArrayLen(int target, int* nums, int numsSize){
    int result = 0;
    int sum = 0;
    int left = 0;
    int right = 0;
    while(right < numsSize){
        sum += nums[right];
        while(sum >= target){
            if(result == 0 || result > right - left + 1){
                result = right - left + 1;
            }
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return result;

}

    