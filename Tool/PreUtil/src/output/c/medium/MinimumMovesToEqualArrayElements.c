/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment n - 1 elements of the array by 1.


int minMoves(int* nums, int numsSize){
    int min = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        count += nums[i] - min;
    }
    return count;

}

    