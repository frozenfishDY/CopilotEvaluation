/**https://leetcode.com/problems/house-robber-ii/ */
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


int rob(int* nums, int numsSize){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if(numsSize == 0){
        return 0;
    }
    if(numsSize == 1){
        return nums[0];
    }
    if(numsSize == 2){
        return fmax(nums[0], nums[1]);
    }
    result[0] = nums[0];
    result[1] = fmax(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++){
        result[i] = fmax(result[i - 1], result[i - 2] + nums[i]);
    }
    return result[numsSize - 1];


}

    