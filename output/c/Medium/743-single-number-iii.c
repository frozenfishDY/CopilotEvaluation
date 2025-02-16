/**https://leetcode.com/problems/single-number-iii/ */
//Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
// 
//Example 1:
//Input: nums = [1,2,1,3,2,5]
//Output: [3,5]
//Explanation:  [5, 3] is also a valid answer.
//Example 2:
//Input: nums = [-1,0]
//Output: [-1,0]
//Example 3:
//Input: nums = [0,1]
//Output: [1,0]
// 
//Constraints:
//	2 <= nums.length <= 3 * 104
//	-231 <= nums[i] <= 231 - 1
//	Each integer in nums will appear twice, only two integers will appear once.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
*returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 2);
    int xor = 0;
    for (int i = 0; i < numsSize; i++) {
        xor ^= nums[i];
    }
    int mask = 1;
    while ((xor & mask) == 0) {
        mask <<= 1;
    }
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & mask) == 0) {
            res[0] ^= nums[i];
        } else {
            res[1] ^= nums[i];
        }
    }
    return res;
}