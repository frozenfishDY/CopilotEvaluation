/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
*returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 2);
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1++;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }
    if (count1 > numsSize / 3) {
        res[(*returnSize)++] = candidate1;
    }
    if (count2 > numsSize / 3) {
        res[(*returnSize)++] = candidate2;
    }
    return res;
}