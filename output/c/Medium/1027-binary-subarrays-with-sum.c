/**https://leetcode.com/problems/binary-subarrays-with-sum/ */
//Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//A subarray is a contiguous part of the array.


int numSubarraysWithSum(int* nums, int numsSize, int goal){
    int* sum = (int*)malloc(sizeof(int) * (numsSize + 1));
    sum[0] = 0;
    for(int i = 1; i <= numsSize; i++){
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j <= numsSize; j++){
            if(sum[j] - sum[i] == goal){
                count++;
            }
        }
    }
    return count;

}

    