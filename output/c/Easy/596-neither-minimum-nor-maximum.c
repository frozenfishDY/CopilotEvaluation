/**https://leetcode.com/problems/neither-minimum-nor-maximum/ */
//Given an integer array nums containing distinct positive integers, find and return any number from the array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.
//Return the selected integer.
// 
//Example 1:
//Input: nums = [3,2,1,4]
//Output: 2
//Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
//Example 2:
//Input: nums = [1,2]
//Output: -1
//Explanation: Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.
//Example 3:
//Input: nums = [2,1,3]
//Output: 2
//Explanation: Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer. 
// 
//Constraints:
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 100
//	All values in nums are distinct
int findNonMinOrMax(int* nums, int numsSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int max = 0;
    int min = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            m = i;
        }
        if (nums[i] < min) {
            min = nums[i];
            l = i;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (i != m && i != l) {
            return nums[i];
        }
    }
    return -1;
}