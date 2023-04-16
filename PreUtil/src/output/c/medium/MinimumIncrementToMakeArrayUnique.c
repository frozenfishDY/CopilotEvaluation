/**https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */
//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.


int minIncrementForUnique(int* nums, int numsSize){
    int* count = (int*)calloc(40000, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }
    int result = 0;
    int taken = 0;
    for(int i = 0; i < 40000; i++){
        if(count[i] >= 2){
            taken += count[i] - 1;
            result -= i * (count[i] - 1);
        }else if(taken > 0 && count[i] == 0){
            taken--;
            result += i;
        }
    }
    return result;

}

    