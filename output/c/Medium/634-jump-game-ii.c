/**https://leetcode.com/problems/jump-game-ii/ */
//You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
//Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
//0 <= j <= nums[i] and
//i + j < n
//Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


int jump(int* nums, int numsSize){
    int jumps = 0;
    int currentJumpEnd = 0;
    int farthest = 0;
    for(int i = 0; i < numsSize - 1; i++){
        farthest = fmax(farthest, i + nums[i]);
        if(i == currentJumpEnd){
            jumps++;
            currentJumpEnd = farthest;
        }
    }
    return jumps;

}

    