/**https://leetcode.com/problems/jump-game/ */
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.


bool canJump(int* nums, int numsSize){
    int max = 0;
    for(int i = 0; i < numsSize; i++){
        if(i > max){
            return false;
        }
        max = fmax(max, i + nums[i]);
    }
    return true;

}

    