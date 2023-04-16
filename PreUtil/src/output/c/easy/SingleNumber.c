/**https://leetcode.com/problems/single-number/ */
//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
//You must implement a solution with a linear runtime complexity and use only constant extra space.

int singleNumber(int* nums, int numsSize){
    int result = 0;
    for(int i = 0; i < numsSize; i++){
        result ^= nums[i];
    }
    return result;

}
    