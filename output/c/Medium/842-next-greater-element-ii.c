/**https://leetcode.com/problems/next-greater-element-ii/ */
//Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
//The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
// 
//Example 1:
//Input: nums = [1,2,1]
//Output: [2,-1,2]
//Explanation: The first 1's next greater number is 2; 
//The number 2 can't find next greater number. 
//The second 1's next greater number needs to search circularly, which is also 2.
//Example 2:
//Input: nums = [1,2,3,4,3]
//Output: [2,3,4,-1,4]
// 
//Constraints:
//	1 <= nums.length <= 104
//	-109 <= nums[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
int* res = (int*)malloc(sizeof(int) * numsSize);
	*returnSize = 0;
	if (numsSize == 0) return res;
	int* stack = (int*)malloc(sizeof(int) * numsSize * 2);
	int top = -1;
	for (int i = 2 * numsSize - 1; i >= 0; i--) {
		while (top != -1 && stack[top] <= nums[i % numsSize]) {
			top--;
		}
		res[(*returnSize)++] = top == -1 ? -1 : stack[top];
		stack[++top] = nums[i % numsSize];
	}
	free(stack);
	return res;
}