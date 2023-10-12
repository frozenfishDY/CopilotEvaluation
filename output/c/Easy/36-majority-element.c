/**https://leetcode.com/problems/majority-element/ */
//Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: 3
//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow-up: Could you solve the problem in linear time and in O(1) space?
int majorityElement(int* nums, int numsSize){
    int i = 0, j = 0;
    int count = 0;
    for (i = 0; i < numsSize; i++) {
        if (count == 0) {
            j = nums[i];
            count++;
        } else {
            if (j == nums[i]) count++;
            else count--;
        }
    }
    return j;
   

}