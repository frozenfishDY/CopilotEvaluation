/**https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/ */
//Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.
//Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// 
//Example 1:
//Input: nums = [1,3,6,10,12,15]
//Output: 9
//Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.
//Example 2:
//Input: nums = [1,2,4,7,10]
//Output: 0
//Explanation: There is no single number that satisfies the requirement, so return 0.
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 1000
int averageValue(int* nums, int numsSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0 && nums[i] % 3 == 0) {
            k += nums[i];
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    return k / n;

}